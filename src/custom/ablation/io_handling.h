#ifndef IO_HANDLING
#define IO_HANDLING

// macros to make io handling easier
#define TRY_IO_GOTO(io_call, expected_result, label) if((io_call) != (expected_result)) { goto label; }
#define TRY_IO_RETURN(io_call, expected_result, error_return_value) if((io_call) != (expected_result)) { return error_return_value; }

#endif