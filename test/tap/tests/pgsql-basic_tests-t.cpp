/**
 * @file pgsql-basic_tests-t.cpp
 * @brief This test conducts a thorough validation of various PostgreSQL database operations.
 * It begins by establishing a valid database connection and confirming successful connectivity.
 * Subsequently, the test performs a series of Data Definition Language (DDL) and Data Manipulation Language (DML) operations,
 * which include table creation, data insertion, selection, updates, deletions, and transactions.
 */

#include <string>
#include <sstream>

#include "libpq-fe.h"
#include "command_line.h"
#include "tap.h"
#include "utils.h"

CommandLine cl;

PGconn* create_new_connection(bool with_ssl) {
    std::stringstream ss;

    ss << "host=" << cl.pgsql_host << " port=" << cl.pgsql_port;
    ss << " user=" << cl.pgsql_username << " password=" << cl.pgsql_password;

    if (with_ssl) {
        ss << " sslmode=require";
    } else { 
        ss << " sslmode=disable";
	}
        
	PGconn* conn = PQconnectdb(ss.str().c_str());
    const bool res = (conn && PQstatus(conn) == CONNECTION_OK);
    ok(res, "Connection created successfully. %s", PQerrorMessage(conn));

    if (res) return conn;

	PQfinish(conn);
	return nullptr;
}

// Function to set up the test environment
void setup_database(PGconn* conn) {
    PGresult* res;

    res = PQexec(conn, "DROP TABLE IF EXISTS test_table");
    PQclear(res);

    res = PQexec(conn, "CREATE TABLE test_table (id SERIAL PRIMARY KEY, value TEXT)");
    ok(PQresultStatus(res) == PGRES_COMMAND_OK, "Created test_table");
    PQclear(res);

    res = PQexec(conn, "INSERT INTO test_table (value) VALUES ('test1'), ('test2'), ('test3')");
    ok(PQresultStatus(res) == PGRES_COMMAND_OK, "Inserted initial records into test_table");
    PQclear(res);
}

void test_simple_query(PGconn* conn) {
    PGresult* res = PQexec(conn, "SELECT 1");
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        ok(1, "Simple SELECT query executed successfully");
        int nFields = PQnfields(res);
        int nRows = PQntuples(res);
        ok(nFields == 1, "Returned one field");
        ok(nRows == 1, "Returned one row");
        char* result = PQgetvalue(res, 0, 0);
        ok(strcmp(result, "1") == 0, "Result is 1");
    } else {
        ok(0, "Simple SELECT query failed");
    }
    PQclear(res);
}

void test_insert_query(PGconn* conn) {
    PGresult* res = PQexec(conn, "INSERT INTO test_table (value) VALUES ('test4')");
    if (PQresultStatus(res) == PGRES_COMMAND_OK) {
        ok(1, "INSERT query executed successfully");
        ok(strcmp(PQcmdTuples(res), "1") == 0, "One row inserted");
    } else {
        ok(0, "INSERT query failed");
    }
    PQclear(res);

    // Verify insertion
    res = PQexec(conn, "SELECT value FROM test_table WHERE value = 'test4'");
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        int nRows = PQntuples(res);
        ok(nRows == 1, "Inserted row is present");
        char* result = PQgetvalue(res, 0, 0);
        ok(strcmp(result, "test4") == 0, "Inserted value is correct");
    } else {
        ok(0, "Failed to verify inserted row");
    }
    PQclear(res);
}

void test_update_query(PGconn* conn) {
    PGresult* res = PQexec(conn, "UPDATE test_table SET value = 'updated' WHERE value = 'test2'");
    if (PQresultStatus(res) == PGRES_COMMAND_OK) {
        ok(1, "UPDATE query executed successfully");
        ok(strcmp(PQcmdTuples(res), "1") == 0, "One row updated");
    } else {
        ok(0, "UPDATE query failed");
    }
    PQclear(res);

    // Verify update
    res = PQexec(conn, "SELECT value FROM test_table WHERE value = 'updated'");
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        int nRows = PQntuples(res);
        ok(nRows == 1, "Updated row is present");
        char* result = PQgetvalue(res, 0, 0);
        ok(strcmp(result, "updated") == 0, "Updated value is correct");
    } else {
        ok(0, "Failed to verify updated row");
    }
    PQclear(res);
}

void test_delete_query(PGconn* conn) {
    PGresult* res = PQexec(conn, "DELETE FROM test_table WHERE value = 'test3'");
    if (PQresultStatus(res) == PGRES_COMMAND_OK) {
        ok(1, "DELETE query executed successfully");
        ok(strcmp(PQcmdTuples(res), "1") == 0, "One row deleted");
    } else {
        ok(0, "DELETE query failed");
    }
    PQclear(res);

    // Verify deletion
    res = PQexec(conn, "SELECT value FROM test_table WHERE value = 'test3'");
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        int nRows = PQntuples(res);
        ok(nRows == 0, "Deleted row is no longer present");
    } else {
        ok(0, "Failed to verify deleted row");
    }
    PQclear(res);
}

void test_invalid_query(PGconn* conn) {
    PGresult* res = PQexec(conn, "SELECT * FROM non_existent_table");
    ok(PQresultStatus(res) == PGRES_FATAL_ERROR, "Query on non-existent table failed as expected");
    PQclear(res);
}

void test_transaction_commit(PGconn* conn) {
    PGresult* res = PQexec(conn, "BEGIN");
    ok(PQtransactionStatus(conn) == PQTRANS_INTRANS, "Connection in Transaction state");
    ok(PQresultStatus(res) == PGRES_COMMAND_OK, "BEGIN transaction");

    res = PQexec(conn, "INSERT INTO test_table (value) VALUES ('transaction commit')");
    ok(PQresultStatus(res) == PGRES_COMMAND_OK, "INSERT in transaction");
    PQclear(res);

    res = PQexec(conn, "COMMIT");
    ok(PQresultStatus(res) == PGRES_COMMAND_OK, "COMMIT transaction");
    PQclear(res);
    ok(PQtransactionStatus(conn) == PQTRANS_IDLE, "Connection in Idle state");

    // Verify commit
    res = PQexec(conn, "SELECT value FROM test_table WHERE value = 'transaction commit'");
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        int nRows = PQntuples(res);
        ok(nRows == 1, "Committed row is present");
        char* result = PQgetvalue(res, 0, 0);
        ok(strcmp(result, "transaction commit") == 0, "Committed value is correct");
    } else {
        ok(0, "Failed to verify committed row");
    }
    PQclear(res);
}

void test_transaction_rollback(PGconn* conn) {
    PGresult* res = PQexec(conn, "BEGIN");
    ok(PQtransactionStatus(conn) == PQTRANS_INTRANS, "Connection in Transaction state");
    ok(PQresultStatus(res) == PGRES_COMMAND_OK, "BEGIN transaction");

    res = PQexec(conn, "INSERT INTO test_table (value) VALUES ('transaction rollback')");
    ok(PQresultStatus(res) == PGRES_COMMAND_OK, "INSERT in transaction");
    PQclear(res);

    res = PQexec(conn, "ROLLBACK");
    ok(PQresultStatus(res) == PGRES_COMMAND_OK, "ROLLBACK transaction");
    PQclear(res);
    ok(PQtransactionStatus(conn) == PQTRANS_IDLE, "Connection in Idle state");

    // Verify rollback
    res = PQexec(conn, "SELECT value FROM test_table WHERE value = 'transaction rollback'");
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        int nRows = PQntuples(res);
        ok(nRows == 0, "Rolled back row is not present");
    } else {
        ok(0, "Failed to verify rolled back row");
    }
    PQclear(res);
}

void test_transaction_error(PGconn* conn) {
    PGresult* res = PQexec(conn, "BEGIN");
    ok(PQtransactionStatus(conn) == PQTRANS_INTRANS, "Connection in Transaction state");
    ok(PQresultStatus(res) == PGRES_COMMAND_OK, "BEGIN transaction");

    res = PQexec(conn, "SELECT 1/0");
    ok(PQresultStatus(res) == PGRES_FATAL_ERROR, "Error result returned");
    PQclear(res);
    ok(PQtransactionStatus(conn) == PQTRANS_INERROR, "Connection in Error Transaction state");

    res = PQexec(conn, "ROLLBACK");
    ok(PQresultStatus(res) == PGRES_COMMAND_OK, "ROLLBACK transaction");
    PQclear(res);
    ok(PQtransactionStatus(conn) == PQTRANS_IDLE, "Connection in Idle state");

    // Verify rollback
    res = PQexec(conn, "SELECT value FROM test_table WHERE value = 'transaction rollback'");
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        int nRows = PQntuples(res);
        ok(nRows == 0, "Rolled back row is not present");
    } else {
        ok(0, "Failed to verify rolled back row");
    }
    PQclear(res);
}

void test_null_value(PGconn* conn) {
    PGresult* res = PQexec(conn, "INSERT INTO test_table (value) VALUES (NULL)");
    if (PQresultStatus(res) == PGRES_COMMAND_OK) {
        ok(1, "INSERT NULL value executed successfully");
        ok(strcmp(PQcmdTuples(res), "1") == 0, "One row inserted with NULL value");
    } else {
        ok(0, "INSERT NULL value failed");
    }
    PQclear(res);

    // Verify NULL insertion
    res = PQexec(conn, "SELECT value FROM test_table WHERE value IS NULL");
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        int nRows = PQntuples(res);
        ok(nRows == 1, "Inserted NULL value is present");
    } else {
        ok(0, "Failed to verify inserted NULL value");
    }
    PQclear(res);
}

void test_constraint_violation(PGconn* conn) {
    PGresult* res = PQexec(conn, "INSERT INTO test_table (id, value) VALUES (1, 'duplicate id')");
    ok(PQresultStatus(res) == PGRES_FATAL_ERROR, "INSERT with duplicate ID failed as expected");
    PQclear(res);
}

void teardown_database(PGconn* conn) {
    PGresult* res;

    res = PQexec(conn, "DROP TABLE IF EXISTS test_table");
    PQclear(res);
}

void test_invalid_connection(bool with_ssl) {

    std::stringstream ss;

    ss << "host=invalid_host port=invalid_port dbname=invalid_db user=invalid_user password=invalid_password";
    
    if (with_ssl) {
        ss << " sslmode=require";
    } else {
        ss << " sslmode=disable";
    }

    PGconn* conn = PQconnectdb(ss.str().c_str());
    ok(PQstatus(conn) == CONNECTION_BAD, "Connection failed with invalid parameters");
    PQfinish(conn);
}

void execute_tests(bool with_ssl) {
    PGconn* conn = create_new_connection(with_ssl);

    if (conn == nullptr)
        return;

    setup_database(conn);
    test_simple_query(conn);
    test_insert_query(conn);
    test_update_query(conn);
    test_delete_query(conn);
    test_invalid_query(conn);
    test_transaction_commit(conn);
    test_transaction_rollback(conn);
    test_transaction_error(conn);
    test_null_value(conn);
    test_constraint_violation(conn);
    teardown_database(conn);
    test_invalid_connection(with_ssl);

    PQfinish(conn);
}

int main(int argc, char** argv) {
    
    plan(88); // Total number of tests planned

    if (cl.getEnv())
        return exit_status();

    execute_tests(false); // without SSL
    execute_tests(true); // with SSL

    return exit_status();
}
