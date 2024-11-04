#include <core.h>

#ifdef DEBUG
#define printf \/\/
#endif

/**
 * @brief Check if paths exists
 *         else create it
 *
 * @return __u_short
 */
__u_short check_path(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file)
    {
        // DEBUG
        printf("File '%s' already exists.\n", filename);
        fclose(file);
        return 0U;
    }
    else
    {
        file = fopen(filename, "w");
        if (file)
        {
            // DEBUG
            printf("File '%s' created successfully.\n", filename);
            fclose(file);
            return 0U;
        }
        else
        {
            // DEBUG
            perror("Error creating file");
            return 1U;
        }
    }
}

/**
 * @brief Set encryption key
 * @return 0 -> Success
 * @return 1 -> Unknown Error
 */
__uint8_t set_encryption_key(char *enc_key)
{
    if (check_path((char *)(ENC_KEY_PATH)) == 1U)
        return 1U;

    FILE *enc_key_file = fopen((char *)(ENC_KEY_PATH), "w");

    unsigned char hash[SHA256_BLOCK_SIZE];

    if (enc_key_file)
    {

        // SHA256 Encryption
        SHA256_CTX ctx;
        sha256_init(&ctx);
        sha256_update(&ctx, (const unsigned char *)enc_key, strlen(enc_key));
        sha256_final(&ctx, hash);

        for (int i = 0; i < SHA256_BLOCK_SIZE; i++)
        {
            fprintf(enc_key_file, "%02x", hash[i]);
        }

        fclose(enc_key_file);
        return 0U;
    }
}