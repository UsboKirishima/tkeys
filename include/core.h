#include <bits/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sha256.h>
#include <string.h>

#define ENC_KEY_PATH "/opt/tkeys/key.enc"

__uint8_t set_encryption_key(char * enc_key);