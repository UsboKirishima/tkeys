#include <option_parser.h>
#include <core.h>

typedef struct {
    char *description;
    __uint8_t (* function)();
} CommandMapper;

CommandMapper options[] = {
    {"Set encryption key", set_encryption_key},
    {"Add password", set_encryption_key},
    {"Edit password", set_encryption_key},
    {"Remove from database", set_encryption_key}
};

void option_parser(__uint8_t option) {

}