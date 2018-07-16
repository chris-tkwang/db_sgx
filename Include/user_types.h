/*
 * Copyright (C) 2011-2018 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* User defined types */

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#define LOOPS_PER_THREAD 500

typedef void *buffer_t;
typedef int array_t[10];

	struct InputBuffer_t {
  		char* buffer;
  		size_t buffer_length;
  		size_t input_length;	
	};
	typedef struct InputBuffer_t InputBuffer;

	enum ExecuteResult_t {
  		EXECUTE_SUCCESS,
 	 	EXECUTE_DUPLICATE_KEY,
  		EXECUTE_TABLE_FULL
	};
	typedef enum ExecuteResult_t ExecuteResult;

	enum MetaCommandResult_t {
  		META_COMMAND_SUCCESS,
  		META_COMMAND_UNRECOGNIZED_COMMAND
	};
	typedef enum MetaCommandResult_t MetaCommandResult;

	enum PrepareResult_t {
  		PREPARE_SUCCESS,
  		PREPARE_NEGATIVE_ID,
  		PREPARE_STRING_TOO_LONG,
  		PREPARE_SYNTAX_ERROR,
  		PREPARE_UNRECOGNIZED_STATEMENT
	};
	typedef enum PrepareResult_t PrepareResult;

	enum StatementType_t { STATEMENT_INSERT, STATEMENT_SELECT };
	typedef enum StatementType_t StatementType;

	struct Row_t {
  		uint32_t id;
  		char username[32];
  		char email[255];
	};
	typedef struct Row_t Row;

	struct Statement_t {
  		StatementType type;
  		Row row_to_insert;  // only used by insert statement
	};
	typedef struct Statement_t Statement;

	struct Pager_t {
  		int file_descriptor;
  		uint32_t file_length;
  		uint32_t num_pages;
  		void* pages[100];
	};
	typedef struct Pager_t Pager;

	struct Table_t {
  		Pager* pager;
  		uint32_t root_page_num;
	};
	typedef struct Table_t Table;

	struct Cursor_t {
  		Table* table;
  		uint32_t page_num;
  		uint32_t cell_num;
  		bool end_of_table;
	};
	typedef struct Cursor_t Cursor;

	enum NodeType_t { NODE_INTERNAL, NODE_LEAF };
	typedef enum NodeType_t NodeType;

