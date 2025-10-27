#ifndef TOKEN_H
#define TOKEN_H

// Line and column for error reporting
typedef struct {
    int line;
    int col;
} Location;

// All possible token types
typedef enum {
    TOKEN_EOF = 0,             // End of File
    TOKEN_TEXT,                // Text content between tags
    TOKEN_LT,                  // <
    TOKEN_GT,                  // >
    TOKEN_SLASH,               // /
    TOKEN_EQUALS,              // =
    TOKEN_IDENTIFIER,          // Tag name or Attribute name (e.g., "div", "src")
    TOKEN_STRING_LITERAL,      // Attribute value (e.g., "my-class")
    TOKEN_DOCTYPE,             // <!DOCTYPE ...> (Lexed but ignored by parser)
    TOKEN_COMMENT,             // <!-- ... --> (Lexed but ignored by parser)
    TOKEN_ERROR                // Lexical Error
} TokenType;

// The token structure
typedef struct {
    TokenType type;
    char *value;
    Location loc;
} Token;

// Global current token instance used by the parser
extern Token current_token;

// Function to get the string representation of a token type
const char *token_type_to_string(TokenType type);

#endif // TOKEN_H
