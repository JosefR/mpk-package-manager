/**
 * @file file.c
 * @author Josef Raschen <josef@raschen.org>
 */
#ifndef _FILE_H
#define _FILE_H

#include <stdbool.h>
#include <sys/queue.h>
#include <openssl/sha.h>
#include "err.h"
#include "string.h"

#define MPK_FILEHASH_SIZE SHA256_DIGEST_LENGTH

/**
 * @brief Metadata for a file in the package.
 */
struct mpk_file {
    char *name; /**< filepath on the target */
    unsigned char hash[MPK_FILEHASH_SIZE]; /**< an SHA256 hash of the file */
    bool hash_is_set; /**< true if #hash has been set */
    LIST_ENTRY(mpk_file) items; /**< linked list metadata */
};

LIST_HEAD(mpk_filelist, mpk_file);

/**
 * @brief mpk_file_create allocates and initialized a file object
 * @return pointer to the file oject or NULL
 */
struct mpk_file *mpk_file_create();

/**
 * @brief mpk_file_delete frees allocated memory of the given file object and
 * setd *file to NULL afterwards
 */
void mpk_file_delete(struct mpk_file **file);

/**
 * @brief mpk_file_hash_serialize coverts a binary file to a hex string
 * @param str the destination; has to offer a buffer of at least
 *      MPK_FILEHASH_SIZE + 1 Bytes
 * @return MPK_SUCCESS or MPK_FAILURE
 */
mpk_ret_t mpk_file_hash_serialize(char *str, struct mpk_file *file);

mpk_ret_t mpk_file_calchash(struct mpk_file *file, const char *basedir);

mpk_ret_t mpk_filelist_init(struct mpk_filelist *list);

void mpk_filelist_delete(struct mpk_filelist *list);

mpk_ret_t mpk_filelist_add(struct mpk_filelist *list, struct mpk_file *file);

mpk_ret_t mpk_filelist_addend(struct mpk_filelist *list, struct mpk_file *file);

#endif /* _FILE_H */
