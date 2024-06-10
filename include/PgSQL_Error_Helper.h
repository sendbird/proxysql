#ifndef __CLASS_PGSQL_ERROR_HELPER_H
#define __CLASS_PGSQL_ERROR_HELPER_H

#include <string>

#define PGSQL_ERROR_FIELD_TEXT				0x0001
#define PGSQL_ERROR_FIELD_DETAIL			0x0002
#define PGSQL_ERROR_FIELD_HINT				0x0004
#define PGSQL_ERROR_FIELD_POSITION			0x0008
#define PGSQL_ERROR_FIELD_INTERNAL_POSITION 0x0010
#define PGSQL_ERROR_FIELD_INTERNAL_QUERY	0x0020
#define PGSQL_ERROR_FIELD_CONTEXT			0x0040
#define PGSQL_ERROR_FIELD_SCHEMA_NAME		0x0080
#define PGSQL_ERROR_FIELD_TABLE_NAME		0x0100
#define PGSQL_ERROR_FIELD_COLUMN_NAME		0x0200
#define PGSQL_ERROR_FIELD_DATA_TYPE_NAME	0x0400
#define PGSQL_ERROR_FIELD_CONSTRAINT_NAME	0x0800
#define PGSQL_ERROR_FIELD_FILE				0x1000
#define PGSQL_ERROR_FIELD_LINE				0x2000
#define PGSQL_ERROR_FIELD_ROUTINE			0x4000
#define PGSQL_ERROR_FIELD_ALL				0xFFFF

// these are standard SQLSTATES
enum class PGSQL_ERROR_CODES : uint8_t {
	ERRCODE_SUCCESSFUL_COMPLETION,
	ERRCODE_WARNING,
	ERRCODE_DYNAMIC_RESULT_SETS_RETURNED,
	ERRCODE_IMPLICIT_ZERO_BIT_PADDING,
	ERRCODE_NULL_VALUE_ELIMINATED_IN_SET_FUNCTION,
	ERRCODE_PRIVILEGE_NOT_GRANTED,
	ERRCODE_PRIVILEGE_NOT_REVOKED,
	ERRCODE_STRING_DATA_RIGHT_TRUNCATION,
	ERRCODE_DEPRECATED_FEATURE,
	ERRCODE_NO_DATA,
	ERRCODE_NO_ADDITIONAL_DYNAMIC_RESULT_SETS_RETURNED,
	ERRCODE_SQL_STATEMENT_NOT_YET_COMPLETE,
	ERRCODE_CONNECTION_EXCEPTION,
	ERRCODE_CONNECTION_DOES_NOT_EXIST,
	ERRCODE_CONNECTION_FAILURE,
	ERRCODE_SQLCLIENT_UNABLE_TO_ESTABLISH_SQLCONNECTION,
	ERRCODE_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION,
	ERRCODE_TRANSACTION_RESOLUTION_UNKNOWN,
	ERRCODE_PROTOCOL_VIOLATION,
	ERRCODE_TRIGGERED_ACTION_EXCEPTION,
	ERRCODE_FEATURE_NOT_SUPPORTED,
	ERRCODE_INVALID_TRANSACTION_INITIATION,
	ERRCODE_LOCATOR_EXCEPTION,
	ERRCODE_INVALID_LOCATOR_SPECIFICATION,
	ERRCODE_INVALID_GRANTOR,
	ERRCODE_INVALID_GRANT_OPERATION,
	ERRCODE_INVALID_ROLE_SPECIFICATION,
	ERRCODE_CARDINALITY_VIOLATION,
	ERRCODE_DATA_EXCEPTION,
	ERRCODE_ARRAY_ELEMENT_ERROR,
	ERRCODE_ARRAY_SUBSCRIPT_ERROR,
	ERRCODE_CHARACTER_NOT_IN_REPERTOIRE,
	ERRCODE_DATETIME_FIELD_OVERFLOW,
	ERRCODE_DIVISION_BY_ZERO,
	ERRCODE_ERROR_IN_ASSIGNMENT,
	ERRCODE_ESCAPE_CHARACTER_CONFLICT,
	ERRCODE_INDICATOR_OVERFLOW,
	ERRCODE_INTERVAL_FIELD_OVERFLOW,
	ERRCODE_INVALID_ARGUMENT_FOR_LOG,
	ERRCODE_INVALID_ARGUMENT_FOR_POWER_FUNCTION,
	ERRCODE_INVALID_ARGUMENT_FOR_WIDTH_BUCKET_FUNCTION,
	ERRCODE_INVALID_CHARACTER_VALUE_FOR_CAST,
	ERRCODE_INVALID_DATETIME_FORMAT,
	ERRCODE_INVALID_ESCAPE_CHARACTER,
	ERRCODE_INVALID_ESCAPE_OCTET,
	ERRCODE_INVALID_ESCAPE_SEQUENCE,
	ERRCODE_NONSTANDARD_USE_OF_ESCAPE_CHARACTER,
	ERRCODE_INVALID_INDICATOR_PARAMETER_VALUE,
	ERRCODE_INVALID_PARAMETER_VALUE,
	ERRCODE_INVALID_REGULAR_EXPRESSION,
	ERRCODE_INVALID_ROW_COUNT_IN_LIMIT_CLAUSE,
	ERRCODE_INVALID_ROW_COUNT_IN_RESULT_OFFSET_CLAUSE,
	ERRCODE_INVALID_TABLESAMPLE_ARGUMENT,
	ERRCODE_INVALID_TABLESAMPLE_REPEAT,
	ERRCODE_INVALID_TIME_ZONE_DISPLACEMENT_VALUE,
	ERRCODE_INVALID_USE_OF_ESCAPE_CHARACTER,
	ERRCODE_MOST_SPECIFIC_TYPE_MISMATCH,
	ERRCODE_NULL_VALUE_NOT_ALLOWED,
	ERRCODE_NULL_VALUE_NO_INDICATOR_PARAMETER,
	ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE,
	ERRCODE_STRING_DATA_LENGTH_MISMATCH,
	ERRCODE_SUBSTRING_ERROR,
	ERRCODE_TRIM_ERROR,
	ERRCODE_UNTERMINATED_C_STRING,
	ERRCODE_ZERO_LENGTH_CHARACTER_STRING,
	ERRCODE_FLOATING_POINT_EXCEPTION,
	ERRCODE_INVALID_TEXT_REPRESENTATION,
	ERRCODE_INVALID_BINARY_REPRESENTATION,
	ERRCODE_BAD_COPY_FILE_FORMAT,
	ERRCODE_UNTRANSLATABLE_CHARACTER,
	ERRCODE_NOT_AN_XML_DOCUMENT,
	ERRCODE_INVALID_XML_DOCUMENT,
	ERRCODE_INVALID_XML_CONTENT,
	ERRCODE_INVALID_XML_COMMENT,
	ERRCODE_INVALID_XML_PROCESSING_INSTRUCTION,
	ERRCODE_INTEGRITY_CONSTRAINT_VIOLATION,
	ERRCODE_RESTRICT_VIOLATION,
	ERRCODE_NOT_NULL_VIOLATION,
	ERRCODE_FOREIGN_KEY_VIOLATION,
	ERRCODE_UNIQUE_VIOLATION,
	ERRCODE_CHECK_VIOLATION,
	ERRCODE_EXCLUSION_VIOLATION,
	ERRCODE_INVALID_CURSOR_STATE,
	ERRCODE_INVALID_TRANSACTION_STATE,
	ERRCODE_ACTIVE_SQL_TRANSACTION,
	ERRCODE_BRANCH_TRANSACTION_ALREADY_ACTIVE,
	ERRCODE_HELD_CURSOR_REQUIRES_SAME_ISOLATION_LEVEL,
	ERRCODE_INAPPROPRIATE_ACCESS_MODE_FOR_BRANCH_TRANSACTION,
	ERRCODE_INAPPROPRIATE_ISOLATION_LEVEL_FOR_BRANCH_TRANSACTION,
	ERRCODE_NO_ACTIVE_SQL_TRANSACTION_FOR_BRANCH_TRANSACTION,
	ERRCODE_READ_ONLY_SQL_TRANSACTION,
	ERRCODE_SCHEMA_AND_DATA_STATEMENT_MIXING_NOT_SUPPORTED,
	ERRCODE_NO_ACTIVE_SQL_TRANSACTION,
	ERRCODE_IN_FAILED_SQL_TRANSACTION,
	ERRCODE_IDLE_IN_TRANSACTION_SESSION_TIMEOUT,
	ERRCODE_INVALID_SQL_STATEMENT_NAME,
	ERRCODE_TRIGGERED_DATA_CHANGE_VIOLATION,
	ERRCODE_INVALID_AUTHORIZATION_SPECIFICATION,
	ERRCODE_INVALID_PASSWORD,
	ERRCODE_DEPENDENT_PRIVILEGE_DESCRIPTORS_STILL_EXIST,
	ERRCODE_DEPENDENT_OBJECTS_STILL_EXIST,
	ERRCODE_INVALID_TRANSACTION_TERMINATION,
	ERRCODE_SQL_ROUTINE_EXCEPTION,
	ERRCODE_S_R_E_FUNCTION_EXECUTED_NO_RETURN_STATEMENT,
	ERRCODE_S_R_E_MODIFYING_SQL_DATA_NOT_PERMITTED,
	ERRCODE_S_R_E_PROHIBITED_SQL_STATEMENT_ATTEMPTED,
	ERRCODE_S_R_E_READING_SQL_DATA_NOT_PERMITTED,
	ERRCODE_INVALID_CURSOR_NAME,
	ERRCODE_EXTERNAL_ROUTINE_EXCEPTION,
	ERRCODE_E_R_E_CONTAINING_SQL_NOT_PERMITTED,
	ERRCODE_E_R_E_MODIFYING_SQL_DATA_NOT_PERMITTED,
	ERRCODE_E_R_E_PROHIBITED_SQL_STATEMENT_ATTEMPTED,
	ERRCODE_E_R_E_READING_SQL_DATA_NOT_PERMITTED,
	ERRCODE_EXTERNAL_ROUTINE_INVOCATION_EXCEPTION,
	ERRCODE_E_R_I_E_INVALID_SQLSTATE_RETURNED,
	ERRCODE_E_R_I_E_NULL_VALUE_NOT_ALLOWED,
	ERRCODE_E_R_I_E_TRIGGER_PROTOCOL_VIOLATED,
	ERRCODE_E_R_I_E_SRF_PROTOCOL_VIOLATED,
	ERRCODE_E_R_I_E_EVENT_TRIGGER_PROTOCOL_VIOLATED,
	ERRCODE_SAVEPOINT_EXCEPTION,
	ERRCODE_S_E_INVALID_SPECIFICATION,
	ERRCODE_INVALID_CATALOG_NAME,
	ERRCODE_INVALID_SCHEMA_NAME,
	ERRCODE_TRANSACTION_ROLLBACK,
	ERRCODE_T_R_INTEGRITY_CONSTRAINT_VIOLATION,
	ERRCODE_T_R_SERIALIZATION_FAILURE,
	ERRCODE_T_R_STATEMENT_COMPLETION_UNKNOWN,
	ERRCODE_T_R_DEADLOCK_DETECTED,
	ERRCODE_SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION,
	ERRCODE_SYNTAX_ERROR,
	ERRCODE_INSUFFICIENT_PRIVILEGE,
	ERRCODE_CANNOT_COERCE,
	ERRCODE_GROUPING_ERROR,
	ERRCODE_WINDOWING_ERROR,
	ERRCODE_INVALID_RECURSION,
	ERRCODE_INVALID_FOREIGN_KEY,
	ERRCODE_INVALID_NAME,
	ERRCODE_NAME_TOO_LONG,
	ERRCODE_RESERVED_NAME,
	ERRCODE_DATATYPE_MISMATCH,
	ERRCODE_INDETERMINATE_DATATYPE,
	ERRCODE_COLLATION_MISMATCH,
	ERRCODE_INDETERMINATE_COLLATION,
	ERRCODE_WRONG_OBJECT_TYPE,
	ERRCODE_GENERATED_ALWAYS,
	ERRCODE_UNDEFINED_COLUMN,
	ERRCODE_UNDEFINED_CURSOR,
	ERRCODE_UNDEFINED_DATABASE,
	ERRCODE_UNDEFINED_FUNCTION,
	ERRCODE_UNDEFINED_PSTATEMENT,
	ERRCODE_UNDEFINED_SCHEMA,
	ERRCODE_UNDEFINED_TABLE,
	ERRCODE_UNDEFINED_PARAMETER,
	ERRCODE_UNDEFINED_OBJECT,
	ERRCODE_DUPLICATE_COLUMN,
	ERRCODE_DUPLICATE_CURSOR,
	ERRCODE_DUPLICATE_DATABASE,
	ERRCODE_DUPLICATE_FUNCTION,
	ERRCODE_DUPLICATE_PSTATEMENT,
	ERRCODE_DUPLICATE_SCHEMA,
	ERRCODE_DUPLICATE_TABLE,
	ERRCODE_DUPLICATE_ALIAS,
	ERRCODE_DUPLICATE_OBJECT,
	ERRCODE_AMBIGUOUS_COLUMN,
	ERRCODE_AMBIGUOUS_FUNCTION,
	ERRCODE_AMBIGUOUS_PARAMETER,
	ERRCODE_AMBIGUOUS_ALIAS,
	ERRCODE_INVALID_COLUMN_REFERENCE,
	ERRCODE_INVALID_COLUMN_DEFINITION,
	ERRCODE_INVALID_CURSOR_DEFINITION,
	ERRCODE_INVALID_DATABASE_DEFINITION,
	ERRCODE_INVALID_FUNCTION_DEFINITION,
	ERRCODE_INVALID_PSTATEMENT_DEFINITION,
	ERRCODE_INVALID_SCHEMA_DEFINITION,
	ERRCODE_INVALID_TABLE_DEFINITION,
	ERRCODE_INVALID_OBJECT_DEFINITION,
	ERRCODE_WITH_CHECK_OPTION_VIOLATION,
	ERRCODE_INSUFFICIENT_RESOURCES,
	ERRCODE_DISK_FULL,
	ERRCODE_OUT_OF_MEMORY,
	ERRCODE_TOO_MANY_CONNECTIONS,
	ERRCODE_CONFIGURATION_LIMIT_EXCEEDED,
	ERRCODE_PROGRAM_LIMIT_EXCEEDED,
	ERRCODE_STATEMENT_TOO_COMPLEX,
	ERRCODE_TOO_MANY_COLUMNS,
	ERRCODE_TOO_MANY_ARGUMENTS,
	ERRCODE_OBJECT_NOT_IN_PREREQUISITE_STATE,
	ERRCODE_OBJECT_IN_USE,
	ERRCODE_CANT_CHANGE_RUNTIME_PARAM,
	ERRCODE_LOCK_NOT_AVAILABLE,
	ERRCODE_UNSAFE_NEW_ENUM_VALUE_USAGE,
	ERRCODE_OPERATOR_INTERVENTION,
	ERRCODE_QUERY_CANCELED,
	ERRCODE_ADMIN_SHUTDOWN,
	ERRCODE_CRASH_SHUTDOWN,
	ERRCODE_CANNOT_CONNECT_NOW,
	ERRCODE_DATABASE_DROPPED,
	ERRCODE_IDLE_SESSION_TIMEOUT,
	ERRCODE_SYSTEM_ERROR,
	ERRCODE_IO_ERROR,
	ERRCODE_UNDEFINED_FILE,
	ERRCODE_DUPLICATE_FILE,
	ERRCODE_CONFIG_FILE_ERROR,
	ERRCODE_LOCK_FILE_EXISTS,
	ERRCODE_FDW_ERROR,
	ERRCODE_FDW_COLUMN_NAME_NOT_FOUND,
	ERRCODE_FDW_DYNAMIC_PARAMETER_VALUE_NEEDED,
	ERRCODE_FDW_FUNCTION_SEQUENCE_ERROR,
	ERRCODE_FDW_INCONSISTENT_DESCRIPTOR_INFORMATION,
	ERRCODE_FDW_INVALID_ATTRIBUTE_VALUE,
	ERRCODE_FDW_INVALID_COLUMN_NAME,
	ERRCODE_FDW_INVALID_COLUMN_NUMBER,
	ERRCODE_FDW_INVALID_DATA_TYPE,
	ERRCODE_FDW_INVALID_DATA_TYPE_DESCRIPTORS,
	ERRCODE_FDW_INVALID_DESCRIPTOR_FIELD_IDENTIFIER,
	ERRCODE_FDW_INVALID_HANDLE,
	ERRCODE_FDW_INVALID_OPTION_INDEX,
	ERRCODE_FDW_INVALID_OPTION_NAME,
	ERRCODE_FDW_INVALID_STRING_LENGTH_OR_BUFFER_LENGTH,
	ERRCODE_FDW_INVALID_STRING_FORMAT,
	ERRCODE_FDW_INVALID_USE_OF_NULL_POINTER,
	ERRCODE_FDW_TOO_MANY_HANDLES,
	ERRCODE_FDW_OUT_OF_MEMORY,
	ERRCODE_FDW_NO_SCHEMAS,
	ERRCODE_FDW_OPTION_NAME_NOT_FOUND,
	ERRCODE_FDW_REPLY_HANDLE,
	ERRCODE_FDW_SCHEMA_NOT_FOUND,
	ERRCODE_FDW_TABLE_NOT_FOUND,
	ERRCODE_FDW_UNABLE_TO_CREATE_EXECUTION,
	ERRCODE_FDW_UNABLE_TO_CREATE_REPLY,
	ERRCODE_FDW_UNABLE_TO_ESTABLISH_CONNECTION,
	ERRCODE_PLPGSQL_ERROR,
	ERRCODE_RAISE_EXCEPTION,
	ERRCODE_ASSERT_FAILURE,
	ERRCODE_INTERNAL_ERROR,
	ERRCODE_DATA_CORRUPTED,
	ERRCODE_INDEX_CORRUPTED,
	// Add more error codes here if needed. Make sure to update error_code_str also.
	ERRCODE_UNKNOWN,
	PGSQL_ERROR_CODES_COUNT  // This should always be the last entry
};

// Enum to represent different error types
enum class PGSQL_ERROR_CLASS : uint8_t {
	ERRCLASS_UNKNOWN_ERROR,
	ERRCLASS_SUCCESS,
	ERRCLASS_WARNING,
	ERRCLASS_NO_DATA,
	ERRCLASS_SQL_STATEMENT_NOT_YET_COMPLETE,
	ERRCLASS_CONNECTION_EXCEPTION,
	ERRCLASS_TRIGGERED_ACTION_EXCEPTION,
	ERRCLASS_FEATURE_NOT_SUPPORTED,
	ERRCLASS_INVALID_TRANSACTION_INITIATION,
	ERRCLASS_LOCATOR_EXCEPTION,
	ERRCLASS_INVALID_GRANTOR,
	ERRCLASS_INVALID_ROLE_SPECIFICATION,
	ERRCLASS_DIAGNOSTICS_EXCEPTION,
	ERRCLASS_CASE_NOT_FOUND,
	ERRCLASS_CARDINALITY_VIOLATION,
	ERRCLASS_DATA_EXCEPTION,
	ERRCLASS_INTEGRITY_CONSTRAINT_VIOLATION,
	ERRCLASS_INVALID_CURSOR_STATE,
	ERRCLASS_INVALID_TRANSACTION_STATE,
	ERRCLASS_INVALID_SQL_STATEMENT_NAME,
	ERRCLASS_TRIGGERED_DATA_CHANGE_VIOLATION,
	ERRCLASS_INVALID_AUTHORIZATION_SPECIFICATION,
	ERRCLASS_DEPENDENT_PRIVILEGE_DESCRIPTORS_STILL_EXIST,
	ERRCLASS_INVALID_TRANSACTION_TERMINATION,
	ERRCLASS_SQL_ROUTINE_EXCEPTION,
	ERRCLASS_INVALID_CURSOR_NAME,
	ERRCLASS_EXTERNAL_ROUTINE_EXCEPTION,
	ERRCLASS_EXTERNAL_ROUTINE_INVOCATION_EXCEPTION,
	ERRCLASS_SAVEPOINT_EXCEPTION,
	ERRCLASS_INVALID_CATALOG_NAME,
	ERRCLASS_INVALID_SCHEMA_NAME,
	ERRCLASS_TRANSACTION_ROLLBACK,
	ERRCLASS_SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION,
	ERRCLASS_WITH_CHECK_OPTION_VIOLATION,
	ERRCLASS_INSUFFICIENT_RESOURCES,
	ERRCLASS_PROGRAM_LIMIT_EXCEEDED,
	ERRCLASS_OBJECT_NOT_IN_PREREQUISITE_STATE,
	ERRCLASS_OPERATOR_INTERVENTION,
	ERRCLASS_SYSTEM_ERROR_UNSPECIFIED,
	ERRCLASS_CONFIG_FILE_ERROR,
	ERRCLASS_CRASH_SHUTDOWN,
	ERRCLASS_PROTOCOL_VIOLATION,
	ERRCLASS_FOREIGN_DATA_WRAPPER_ERROR,
	ERRCLASS_PLPGSQL_ERROR,
	ERRCLASS_INTERNAL_ERROR,
	ERRCLASS_MYSQL_SPECIFIC_ERROR
};

// Enum to represent error categories
enum class PGSQL_ERROR_CATEGORY : uint8_t {
	ERRCATEGORY_UNKNOWN_CATEGORY,
	ERRCATEGORY_STATUS, // For success and warnings, which are not errors.
	ERRCATEGORY_CLIENT_ERROR,
	ERRCATEGORY_CONNECTION_ERROR,
	ERRCATEGORY_AUTHORIZATION_ERROR,
	ERRCATEGORY_RESOURCE_ERROR,
	ERRCATEGORY_CONFIGURATION_ERROR,
	ERRCATEGORY_SYNTAX_ERROR,
	ERRCATEGORY_FEATURE_NOT_SUPPORTED,
	ERRCATEGORY_TRANSACTION_ERROR,
	ERRCATEGORY_DATA_ERROR,
	ERRCATEGORY_ROUTINE_ERROR,
	ERRCATEGORY_CURSOR_ERROR,
	ERRCATEGORY_EXTERNAL_ROUTINE_ERROR,
	ERRCATEGORY_RESOURCE_LIMIT_ERROR,
	ERRCATEGORY_OBJECT_STATE_ERROR,
	ERRCATEGORY_OPERATOR_INTERVENTION_ERROR,
	ERRCATEGORY_FDW_ERROR,
	ERRCATEGORY_PLPGSQL_ERROR,
	ERRCATEGORY_INTERNAL_ERROR_CATEGORY
};

enum class PGSQL_ERROR_SEVERITY : uint8_t {
	ERRSEVERITY_UNKNOWN_SEVERITY,
	ERRSEVERITY_FATAL,
	ERRSEVERITY_PANIC,
	ERRSEVERITY_ERROR,
	ERRSEVERITY_WARNING,
	ERRSEVERITY_NOTICE,
	ERRSEVERITY_DEBUG,
	ERRSEVERITY_INFO,
	ERRSEVERITY_LOG,
	PGSQL_ERROR_SEVERITY_COUNT
};

struct PgSQL_ErrorInfo_Ext {
	// bitmap fields present in the error message
	PGSQL_ERROR_SEVERITY text;
	std::string detail;
	std::string hint;
	std::string position;
	std::string internal_position;
	std::string internal_query;
	std::string context;
	std::string schema_name;
	std::string table_name;
	std::string column_name;
	std::string datatype_name;
	std::string constraint_name;
	std::string source_file;
	std::string source_line;
	std::string source_function;
	void reset();
};

struct pg_result;
typedef struct pg_result PGresult;

struct PgSQL_ErrorInfo {
	PGSQL_ERROR_SEVERITY severity = PGSQL_ERROR_SEVERITY::ERRSEVERITY_UNKNOWN_SEVERITY;
	PGSQL_ERROR_CODES code = PGSQL_ERROR_CODES::ERRCODE_SUCCESSFUL_COMPLETION;
	PGSQL_ERROR_CLASS type = PGSQL_ERROR_CLASS::ERRCLASS_UNKNOWN_ERROR;
	PGSQL_ERROR_CATEGORY category = PGSQL_ERROR_CATEGORY::ERRCATEGORY_UNKNOWN_CATEGORY;
	char sqlstate[5 + 1] = {}; // 5 bytes for SQLSTATE + 1 for null terminator
	PgSQL_ErrorInfo_Ext* ext_info = NULL;
	std::string message;
};

void reset_error_info(PgSQL_ErrorInfo& err_info, bool release_extented);

class PgSQL_Error_Helper {
public:
	static constexpr const char* get_error_code(PGSQL_ERROR_CODES err_code) {
		return error_code_str[static_cast<uint8_t>(err_code)];
	}

	static void fill_error_info(PgSQL_ErrorInfo& err_info, const PGresult* result, uint16_t ext_fields);
	static void fill_error_info(PgSQL_ErrorInfo& err_info, const char* code, const char* msg, const char* severity);

private:
	static PGSQL_ERROR_CODES identify_error_code(const char* code);
	static PGSQL_ERROR_CLASS identify_error_class(const char* code);
	static PGSQL_ERROR_CATEGORY categorize_error_class(PGSQL_ERROR_CLASS err_class);
	static PGSQL_ERROR_SEVERITY identify_error_severity(const char* severity);
	static void fill_extended_error_info(PgSQL_ErrorInfo& err_info, const PGresult* result, uint16_t ext_fields);

	/* All the error codes from https://www.postgresql.org/docs/current/errcodes-appendix.html */
	static constexpr const char* error_code_str[] = {
		"00000", // ERRCODE_SUCCESSFUL_COMPLETION
		"01000", // ERRCODE_WARNING
		"0100C", // ERRCODE_DYNAMIC_RESULT_SETS_RETURNED
		"01008", // ERRCODE_IMPLICIT_ZERO_BIT_PADDING
		"01003", // ERRCODE_NULL_VALUE_ELIMINATED_IN_SET_FUNCTION
		"01007", // ERRCODE_PRIVILEGE_NOT_GRANTED
		"01006", // ERRCODE_PRIVILEGE_NOT_REVOKED
		"01004", // ERRCODE_STRING_DATA_RIGHT_TRUNCATION
		"01P01", // ERRCODE_DEPRECATED_FEATURE
		"02000", // ERRCODE_NO_DATA
		"02001", // ERRCODE_NO_ADDITIONAL_DYNAMIC_RESULT_SETS_RETURNED
		"03000", // ERRCODE_SQL_STATEMENT_NOT_YET_COMPLETE
		"08000", // ERRCODE_CONNECTION_EXCEPTION
		"08003", // ERRCODE_CONNECTION_DOES_NOT_EXIST
		"08006", // ERRCODE_CONNECTION_FAILURE
		"08001", // ERRCODE_SQLCLIENT_UNABLE_TO_ESTABLISH_SQLCONNECTION
		"08004", // ERRCODE_SQLSERVER_REJECTED_ESTABLISHMENT_OF_SQLCONNECTION
		"08007", // ERRCODE_TRANSACTION_RESOLUTION_UNKNOWN
		"08P01", // ERRCODE_PROTOCOL_VIOLATION
		"09000", // ERRCODE_TRIGGERED_ACTION_EXCEPTION
		"0A000", // ERRCODE_FEATURE_NOT_SUPPORTED
		"0B000", // ERRCODE_INVALID_TRANSACTION_INITIATION
		"0F000", // ERRCODE_LOCATOR_EXCEPTION
		"0F001", // ERRCODE_INVALID_LOCATOR_SPECIFICATION
		"0L000", // ERRCODE_INVALID_GRANTOR
		"0LP01", // ERRCODE_INVALID_GRANT_OPERATION
		"0P000", // ERRCODE_INVALID_ROLE_SPECIFICATION
		"21000", // ERRCODE_CARDINALITY_VIOLATION
		"22000", // ERRCODE_DATA_EXCEPTION
		"2202E", // ERRCODE_ARRAY_ELEMENT_ERROR
		"2202E", // ERRCODE_ARRAY_SUBSCRIPT_ERROR
		"22021", // ERRCODE_CHARACTER_NOT_IN_REPERTOIRE
		"22008", // ERRCODE_DATETIME_FIELD_OVERFLOW
		"22012", // ERRCODE_DIVISION_BY_ZERO
		"22005", // ERRCODE_ERROR_IN_ASSIGNMENT
		"2200B", // ERRCODE_ESCAPE_CHARACTER_CONFLICT
		"22022", // ERRCODE_INDICATOR_OVERFLOW
		"22015", // ERRCODE_INTERVAL_FIELD_OVERFLOW
		"2201E", // ERRCODE_INVALID_ARGUMENT_FOR_LOG
		"2201F", // ERRCODE_INVALID_ARGUMENT_FOR_POWER_FUNCTION
		"2201G", // ERRCODE_INVALID_ARGUMENT_FOR_WIDTH_BUCKET_FUNCTION
		"22018", // ERRCODE_INVALID_CHARACTER_VALUE_FOR_CAST
		"22007", // ERRCODE_INVALID_DATETIME_FORMAT
		"22019", // ERRCODE_INVALID_ESCAPE_CHARACTER
		"2200D", // ERRCODE_INVALID_ESCAPE_OCTET
		"22025", // ERRCODE_INVALID_ESCAPE_SEQUENCE
		"22P06", // ERRCODE_NONSTANDARD_USE_OF_ESCAPE_CHARACTER
		"22010", // ERRCODE_INVALID_INDICATOR_PARAMETER_VALUE
		"22023", // ERRCODE_INVALID_PARAMETER_VALUE
		"2201B", // ERRCODE_INVALID_REGULAR_EXPRESSION
		"2201W", // ERRCODE_INVALID_ROW_COUNT_IN_LIMIT_CLAUSE
		"2201X", // ERRCODE_INVALID_ROW_COUNT_IN_RESULT_OFFSET_CLAUSE
		"2202H", // ERRCODE_INVALID_TABLESAMPLE_ARGUMENT
		"2202G", // ERRCODE_INVALID_TABLESAMPLE_REPEAT
		"22009", // ERRCODE_INVALID_TIME_ZONE_DISPLACEMENT_VALUE
		"2200C", // ERRCODE_INVALID_USE_OF_ESCAPE_CHARACTER
		"2200G", // ERRCODE_MOST_SPECIFIC_TYPE_MISMATCH
		"22004", // ERRCODE_NULL_VALUE_NOT_ALLOWED
		"22002", // ERRCODE_NULL_VALUE_NO_INDICATOR_PARAMETER
		"22003", // ERRCODE_NUMERIC_VALUE_OUT_OF_RANGE
		"22026", // ERRCODE_STRING_DATA_LENGTH_MISMATCH
		"22011", // ERRCODE_SUBSTRING_ERROR
		"22027", // ERRCODE_TRIM_ERROR
		"22024", // ERRCODE_UNTERMINATED_C_STRING
		"2200F", // ERRCODE_ZERO_LENGTH_CHARACTER_STRING
		"22P01", // ERRCODE_FLOATING_POINT_EXCEPTION
		"22P02", // ERRCODE_INVALID_TEXT_REPRESENTATION
		"22P03", // ERRCODE_INVALID_BINARY_REPRESENTATION
		"22P04", // ERRCODE_BAD_COPY_FILE_FORMAT
		"22P05", // ERRCODE_UNTRANSLATABLE_CHARACTER
		"2200L", // ERRCODE_NOT_AN_XML_DOCUMENT
		"2200M", // ERRCODE_INVALID_XML_DOCUMENT
		"2200N", // ERRCODE_INVALID_XML_CONTENT
		"2200S", // ERRCODE_INVALID_XML_COMMENT
		"2200T", // ERRCODE_INVALID_XML_PROCESSING_INSTRUCTION
		"23000", // ERRCODE_INTEGRITY_CONSTRAINT_VIOLATION
		"23001", // ERRCODE_RESTRICT_VIOLATION
		"23502", // ERRCODE_NOT_NULL_VIOLATION
		"23503", // ERRCODE_FOREIGN_KEY_VIOLATION
		"23505", // ERRCODE_UNIQUE_VIOLATION
		"23514", // ERRCODE_CHECK_VIOLATION
		"23P01", // ERRCODE_EXCLUSION_VIOLATION
		"24000", // ERRCODE_INVALID_CURSOR_STATE
		"25000", // ERRCODE_INVALID_TRANSACTION_STATE
		"25001", // ERRCODE_ACTIVE_SQL_TRANSACTION
		"25002", // ERRCODE_BRANCH_TRANSACTION_ALREADY_ACTIVE
		"25008", // ERRCODE_HELD_CURSOR_REQUIRES_SAME_ISOLATION_LEVEL
		"25003", // ERRCODE_INAPPROPRIATE_ACCESS_MODE_FOR_BRANCH_TRANSACTION
		"25004", // ERRCODE_INAPPROPRIATE_ISOLATION_LEVEL_FOR_BRANCH_TRANSACTION
		"25005", // ERRCODE_NO_ACTIVE_SQL_TRANSACTION_FOR_BRANCH_TRANSACTION
		"25006", // ERRCODE_READ_ONLY_SQL_TRANSACTION
		"25007", // ERRCODE_SCHEMA_AND_DATA_STATEMENT_MIXING_NOT_SUPPORTED
		"25P01", // ERRCODE_NO_ACTIVE_SQL_TRANSACTION
		"25P02", // ERRCODE_IN_FAILED_SQL_TRANSACTION
		"25P03", // ERRCODE_IDLE_IN_TRANSACTION_SESSION_TIMEOUT
		"26000", // ERRCODE_INVALID_SQL_STATEMENT_NAME
		"27000", // ERRCODE_TRIGGERED_DATA_CHANGE_VIOLATION
		"28000", // ERRCODE_INVALID_AUTHORIZATION_SPECIFICATION
		"28P01", // ERRCODE_INVALID_PASSWORD
		"2B000", // ERRCODE_DEPENDENT_PRIVILEGE_DESCRIPTORS_STILL_EXIST
		"2BP01", // ERRCODE_DEPENDENT_OBJECTS_STILL_EXIST
		"2D000", // ERRCODE_INVALID_TRANSACTION_TERMINATION
		"2F000", // ERRCODE_SQL_ROUTINE_EXCEPTION
		"2F005", // ERRCODE_S_R_E_FUNCTION_EXECUTED_NO_RETURN_STATEMENT
		"2F002", // ERRCODE_S_R_E_MODIFYING_SQL_DATA_NOT_PERMITTED
		"2F003", // ERRCODE_S_R_E_PROHIBITED_SQL_STATEMENT_ATTEMPTED
		"2F004", // ERRCODE_S_R_E_READING_SQL_DATA_NOT_PERMITTED
		"34000", // ERRCODE_INVALID_CURSOR_NAME
		"38000", // ERRCODE_EXTERNAL_ROUTINE_EXCEPTION
		"38001", // ERRCODE_E_R_E_CONTAINING_SQL_NOT_PERMITTED
		"38002", // ERRCODE_E_R_E_MODIFYING_SQL_DATA_NOT_PERMITTED
		"38003", // ERRCODE_E_R_E_PROHIBITED_SQL_STATEMENT_ATTEMPTED
		"38004", // ERRCODE_E_R_E_READING_SQL_DATA_NOT_PERMITTED
		"39000", // ERRCODE_EXTERNAL_ROUTINE_INVOCATION_EXCEPTION
		"39001", // ERRCODE_E_R_I_E_INVALID_SQLSTATE_RETURNED
		"39004", // ERRCODE_E_R_I_E_NULL_VALUE_NOT_ALLOWED
		"39P01", // ERRCODE_E_R_I_E_TRIGGER_PROTOCOL_VIOLATED
		"39P02", // ERRCODE_E_R_I_E_SRF_PROTOCOL_VIOLATED
		"39P03", // ERRCODE_E_R_I_E_EVENT_TRIGGER_PROTOCOL_VIOLATED
		"3B000", // ERRCODE_SAVEPOINT_EXCEPTION
		"3B001", // ERRCODE_S_E_INVALID_SPECIFICATION
		"3D000", // ERRCODE_INVALID_CATALOG_NAME
		"3F000", // ERRCODE_INVALID_SCHEMA_NAME
		"40000", // ERRCODE_TRANSACTION_ROLLBACK
		"40002", // ERRCODE_T_R_INTEGRITY_CONSTRAINT_VIOLATION
		"40001", // ERRCODE_T_R_SERIALIZATION_FAILURE
		"40003", // ERRCODE_T_R_STATEMENT_COMPLETION_UNKNOWN
		"40P01", // ERRCODE_T_R_DEADLOCK_DETECTED
		"42000", // ERRCODE_SYNTAX_ERROR_OR_ACCESS_RULE_VIOLATION
		"42601", // ERRCODE_SYNTAX_ERROR
		"42501", // ERRCODE_INSUFFICIENT_PRIVILEGE
		"42846", // ERRCODE_CANNOT_COERCE
		"42803", // ERRCODE_GROUPING_ERROR
		"42P20", // ERRCODE_WINDOWING_ERROR
		"42P19", // ERRCODE_INVALID_RECURSION
		"42830", // ERRCODE_INVALID_FOREIGN_KEY
		"42602", // ERRCODE_INVALID_NAME
		"42622", // ERRCODE_NAME_TOO_LONG
		"42939", // ERRCODE_RESERVED_NAME
		"42804", // ERRCODE_DATATYPE_MISMATCH
		"42P18", // ERRCODE_INDETERMINATE_DATATYPE
		"42P21", // ERRCODE_COLLATION_MISMATCH
		"42P22", // ERRCODE_INDETERMINATE_COLLATION
		"42809", // ERRCODE_WRONG_OBJECT_TYPE
		"428C9", // ERRCODE_GENERATED_ALWAYS
		"42703", // ERRCODE_UNDEFINED_COLUMN
		"34000", // ERRCODE_UNDEFINED_CURSOR
		"3D000", // ERRCODE_UNDEFINED_DATABASE
		"42883", // ERRCODE_UNDEFINED_FUNCTION
		"26000", // ERRCODE_UNDEFINED_PSTATEMENT
		"3F000", // ERRCODE_UNDEFINED_SCHEMA
		"42P01", // ERRCODE_UNDEFINED_TABLE
		"42P02", // ERRCODE_UNDEFINED_PARAMETER
		"42704", // ERRCODE_UNDEFINED_OBJECT
		"42701", // ERRCODE_DUPLICATE_COLUMN
		"42P03", // ERRCODE_DUPLICATE_CURSOR
		"42P04", // ERRCODE_DUPLICATE_DATABASE
		"42723", // ERRCODE_DUPLICATE_FUNCTION
		"42P05", // ERRCODE_DUPLICATE_PSTATEMENT
		"42P06", // ERRCODE_DUPLICATE_SCHEMA
		"42P07", // ERRCODE_DUPLICATE_TABLE
		"42712", // ERRCODE_DUPLICATE_ALIAS
		"42710", // ERRCODE_DUPLICATE_OBJECT
		"42702", // ERRCODE_AMBIGUOUS_COLUMN
		"42725", // ERRCODE_AMBIGUOUS_FUNCTION
		"42P08", // ERRCODE_AMBIGUOUS_PARAMETER
		"42P09", // ERRCODE_AMBIGUOUS_ALIAS
		"42P10", // ERRCODE_INVALID_COLUMN_REFERENCE
		"42611", // ERRCODE_INVALID_COLUMN_DEFINITION
		"42P11", // ERRCODE_INVALID_CURSOR_DEFINITION
		"42P12", // ERRCODE_INVALID_DATABASE_DEFINITION
		"42P13", // ERRCODE_INVALID_FUNCTION_DEFINITION
		"42P14", // ERRCODE_INVALID_PSTATEMENT_DEFINITION
		"42P15", // ERRCODE_INVALID_SCHEMA_DEFINITION
		"42P16", // ERRCODE_INVALID_TABLE_DEFINITION
		"42P17", // ERRCODE_INVALID_OBJECT_DEFINITION
		"44000", // ERRCODE_WITH_CHECK_OPTION_VIOLATION
		"53000", // ERRCODE_INSUFFICIENT_RESOURCES
		"53100", // ERRCODE_DISK_FULL
		"53200", // ERRCODE_OUT_OF_MEMORY
		"53300", // ERRCODE_TOO_MANY_CONNECTIONS
		"53400", // ERRCODE_CONFIGURATION_LIMIT_EXCEEDED
		"54000", // ERRCODE_PROGRAM_LIMIT_EXCEEDED
		"54001", // ERRCODE_STATEMENT_TOO_COMPLEX
		"54011", // ERRCODE_TOO_MANY_COLUMNS
		"54023", // ERRCODE_TOO_MANY_ARGUMENTS
		"55000", // ERRCODE_OBJECT_NOT_IN_PREREQUISITE_STATE
		"55006", // ERRCODE_OBJECT_IN_USE
		"55P02", // ERRCODE_CANT_CHANGE_RUNTIME_PARAM
		"55P03", // ERRCODE_LOCK_NOT_AVAILABLE
		"55P04", // ERRCODE_UNSAFE_NEW_ENUM_VALUE_USAGE
		"57000", // ERRCODE_OPERATOR_INTERVENTION
		"57014", // ERRCODE_QUERY_CANCELED
		"57P01", // ERRCODE_ADMIN_SHUTDOWN
		"57P02", // ERRCODE_CRASH_SHUTDOWN
		"57P03", // ERRCODE_CANNOT_CONNECT_NOW
		"57P04", // ERRCODE_DATABASE_DROPPED
		"57P05", // ERRCODE_IDLE_SESSION_TIMEOUT
		"58000", // ERRCODE_SYSTEM_ERROR
		"58030", // ERRCODE_IO_ERROR
		"58P01", // ERRCODE_UNDEFINED_FILE
		"58P02", // ERRCODE_DUPLICATE_FILE
		"F0000", // ERRCODE_CONFIG_FILE_ERROR
		"F0001", // ERRCODE_LOCK_FILE_EXISTS
		"HV000", // ERRCODE_FDW_ERROR
		"HV005", // ERRCODE_FDW_COLUMN_NAME_NOT_FOUND
		"HV002", // ERRCODE_FDW_DYNAMIC_PARAMETER_VALUE_NEEDED
		"HV010", // ERRCODE_FDW_FUNCTION_SEQUENCE_ERROR
		"HV021", // ERRCODE_FDW_INCONSISTENT_DESCRIPTOR_INFORMATION
		"HV024", // ERRCODE_FDW_INVALID_ATTRIBUTE_VALUE
		"HV007", // ERRCODE_FDW_INVALID_COLUMN_NAME
		"HV008", // ERRCODE_FDW_INVALID_COLUMN_NUMBER
		"HV004", // ERRCODE_FDW_INVALID_DATA_TYPE
		"HV006", // ERRCODE_FDW_INVALID_DATA_TYPE_DESCRIPTORS
		"HV091", // ERRCODE_FDW_INVALID_DESCRIPTOR_FIELD_IDENTIFIER
		"HV00B", // ERRCODE_FDW_INVALID_HANDLE
		"HV00C", // ERRCODE_FDW_INVALID_OPTION_INDEX
		"HV00D", // ERRCODE_FDW_INVALID_OPTION_NAME
		"HV090", // ERRCODE_FDW_INVALID_STRING_LENGTH_OR_BUFFER_LENGTH
		"HV00A", // ERRCODE_FDW_INVALID_STRING_FORMAT
		"HV009", // ERRCODE_FDW_INVALID_USE_OF_NULL_POINTER
		"HV014", // ERRCODE_FDW_TOO_MANY_HANDLES
		"HV001", // ERRCODE_FDW_OUT_OF_MEMORY
		"HV00P", // ERRCODE_FDW_NO_SCHEMAS
		"HV00J", // ERRCODE_FDW_OPTION_NAME_NOT_FOUND
		"HV00K", // ERRCODE_FDW_REPLY_HANDLE
		"HV00Q", // ERRCODE_FDW_SCHEMA_NOT_FOUND
		"HV00R", // ERRCODE_FDW_TABLE_NOT_FOUND
		"HV00L", // ERRCODE_FDW_UNABLE_TO_CREATE_EXECUTION
		"HV00M", // ERRCODE_FDW_UNABLE_TO_CREATE_REPLY
		"HV00N", // ERRCODE_FDW_UNABLE_TO_ESTABLISH_CONNECTION
		"P0000", // ERRCODE_PLPGSQL_ERROR
		"P0001", // ERRCODE_RAISE_EXCEPTION
		"P0002", // ERRCODE_ASSERT_FAILURE
		"XX000", // ERRCODE_INTERNAL_ERROR
		"XX001", // ERRCODE_DATA_CORRUPTED
		"XX002", // ERRCODE_INDEX_CORRUPTED
		// Add more error codes here if needed. Make sure to update PGSQL_ERROR_CODES also.
		"XXXXX",  // ERRCODE_UNKNOWN
	};

	static_assert(static_cast<uint8_t>(PGSQL_ERROR_CODES::PGSQL_ERROR_CODES_COUNT) == sizeof(error_code_str) / sizeof(char*), "Mismatch between PGSQL_ERROR_CODES_COUNT and error_code_str array size");
};

#define PGSQL_GET_ERROR_CODE_STR(ENUM_CODE) PgSQL_Error_Helper::get_error_code(PGSQL_ERROR_CODES::ENUM_CODE)

#endif /* __CLASS_PGSQL_ERROR_HELPER_H */
