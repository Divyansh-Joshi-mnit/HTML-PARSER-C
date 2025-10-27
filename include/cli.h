#ifndef CLI_H
#define CLI_H

// Structure to hold parsed command line options
typedef struct {
    char *input_filepath;
    int print_dom;      // --print-dom
    int validate_only;  // --validate-only
    int print_tokens;   // --tokens
} CliOptions;

// Function to parse command-line arguments
CliOptions parse_cli_arguments(int argc, char *argv[]);

#endif // CLI_H