#ifndef DOM_H
#define DOM_H

#include <stddef.h>
#include "token.h"

// Node types in the DOM tree
typedef enum {
    NODE_TYPE_ELEMENT,
    NODE_TYPE_TEXT
} NodeType;

// Structure for a basic attribute
typedef struct Attribute {
    char *name;
    char *value;
    struct Attribute *next;
} Attribute;

// Structure for a DOM tree node
typedef struct DOMNode {
    NodeType type;
    char *tag_name;     // Used if type == NODE_TYPE_ELEMENT
    char *text_content; // Used if type == NODE_TYPE_TEXT

    Attribute *attributes;

    struct DOMNode **children;
    size_t children_count;
    size_t children_capacity;

    struct DOMNode *parent;
} DOMNode;

// Function declarations
DOMNode *dom_node_create_element(const char *tag_name);
DOMNode *dom_node_create_text(const char *text_content);
void dom_node_append_child(DOMNode *parent, DOMNode *child);
void dom_node_add_attribute(DOMNode *node, const char *name, const char *value);
void dom_node_destroy(DOMNode *node);
void dom_node_print(DOMNode *node, int indent);

#endif // DOM_H