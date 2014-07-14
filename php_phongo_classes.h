/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 2014 Hannes Magnusson                                  |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Hannes Magnusson <bjori@php.net>                             |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHONGO_CLASSES_H
#define PHONGO_CLASSES_H

typedef struct {
	zend_object              std;
	bson_t                  *bson;
} php_phongo_command_t;

typedef struct {
	zend_object              std;
	zend_class_entry        *ce_get_iterator;
	mongoc_cursor_t         *cursor;
	bson_t                  *firstBatch;
	int                      hint;
} php_phongo_result_t;

typedef struct {
	php_phongo_result_t      result;
} php_phongo_commandresult_t;

typedef struct {
	zend_object              std;
} php_phongo_cursor_t;

typedef struct {
	zend_object              std;
} php_phongo_cursorid_t;

typedef struct {
	zend_object              std;
} php_phongo_generatedid_t;

typedef struct {
	zend_object              std;
	mongoc_client_t         *client;
} php_phongo_manager_t;

typedef struct {
	zend_object              std;
	bson_t                  *bson;
	bson_t                  *selector;
	mongoc_query_flags_t     flags;
	uint32_t                 skip;
	uint32_t                 limit;
	uint32_t                 batch_size;
} php_phongo_query_t;

typedef struct {
	zend_object              std;
} php_phongo_queryresult_t;

typedef struct {
	zend_object              std;
	mongoc_read_prefs_t     *read_preference;
} php_phongo_readpreference_t;

typedef struct {
	zend_object              std;
	mongoc_host_list_t      *host;
	int hint;
} php_phongo_server_t;

typedef struct {
	zend_object              std;
	mongoc_bulk_operation_t *batch;
} php_phongo_writebatch_t;

typedef struct {
	zend_object              std;
} php_phongo_writeconcernerror_t;

typedef struct {
	zend_object              std;
} php_phongo_writeerror_t;

typedef struct {
	zend_object              std;
	zend_bool                initialized;
	int                      nInserted;
	int                      nMatched;
	int                      nModified;
	int                      nRemoved;
	int                      nUpserted;
} php_phongo_writeresult_t;

extern PHONGO_API zend_class_entry *php_phongo_command_ce;
extern PHONGO_API zend_class_entry *php_phongo_commandresult_ce;
extern PHONGO_API zend_class_entry *php_phongo_cursor_ce;
extern PHONGO_API zend_class_entry *php_phongo_cursorid_ce;
extern PHONGO_API zend_class_entry *php_phongo_generatedid_ce;
extern PHONGO_API zend_class_entry *php_phongo_manager_ce;
extern PHONGO_API zend_class_entry *php_phongo_query_ce;
extern PHONGO_API zend_class_entry *php_phongo_queryresult_ce;
extern PHONGO_API zend_class_entry *php_phongo_readpreference_ce;
extern PHONGO_API zend_class_entry *php_phongo_result_ce;
extern PHONGO_API zend_class_entry *php_phongo_server_ce;
extern PHONGO_API zend_class_entry *php_phongo_writebatch_ce;
extern PHONGO_API zend_class_entry *php_phongo_writeconcernerror_ce;
extern PHONGO_API zend_class_entry *php_phongo_writeerror_ce;
extern PHONGO_API zend_class_entry *php_phongo_writeresult_ce;

PHP_MINIT_FUNCTION(Command);
PHP_MINIT_FUNCTION(CommandResult);
PHP_MINIT_FUNCTION(Cursor);
PHP_MINIT_FUNCTION(CursorId);
PHP_MINIT_FUNCTION(GeneratedId);
PHP_MINIT_FUNCTION(Manager);
PHP_MINIT_FUNCTION(Query);
PHP_MINIT_FUNCTION(QueryResult);
PHP_MINIT_FUNCTION(ReadPreference);
PHP_MINIT_FUNCTION(Result);
PHP_MINIT_FUNCTION(Server);
PHP_MINIT_FUNCTION(WriteBatch);
PHP_MINIT_FUNCTION(WriteConcernError);
PHP_MINIT_FUNCTION(WriteError);
PHP_MINIT_FUNCTION(WriteResult);
#endif /* PHONGO_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
