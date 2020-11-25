/* RCS  $Id: public.h,v 1.9 2007-10-15 15:54:51 ihi Exp $
-- WARNING  -- This file is AUTOMATICALLY GENERATED DO NOT EDIT IT
--
--
-- SYNOPSIS
--      Local functions exported to be visible by others.
--
-- DESCRIPTION
--      This file is generated by 'genpub'.  Function declarations
--      that appear in this file are extracted by 'genpub' from
--      source files.  Any function in the source file whose definition
--      appears like:
--
--          PUBLIC return_type
--          function( arg_list );
--          type_expr1 arg1;
--          ...
--
--      has its definition extracted and a line of the form:
--
--          return_type function ANSI((type_expr1,type_expr2,...));
--
--      entered into the output file.
--
-- AUTHOR
--      Dennis Vadura, dvadura@dmake.wticorp.com
--
-- WWW
--      http://dmake.wticorp.com/
--
-- COPYRIGHT
--      Copyright (c) 1996,1997 by WTI Corp.  All rights reserved.
-- 
--      This program is NOT free software; you can redistribute it and/or
--      modify it under the terms of the Software License Agreement Provided
--      in the file <distribution-root>/COPYING.
--
-- LOG
--      Use cvs log to obtain detailed change logs.
*/

#ifndef _DMAKE_PUBLIC_h
#define _DMAKE_PUBLIC_h

#ifdef EXTERN
#undef EXTERN
#endif
#if defined(DEFINE_DMAKE_VARIABLES)
#define EXTERN
#else
#define EXTERN extern
#endif

/***** genpub: Begin list of generated function headers */
void Infer_recipe ANSI((CELLPTR, CELLPTR));
int Make_targets ANSI(());
int Make ANSI((CELLPTR, CELLPTR));
int Exec_commands ANSI((CELLPTR));
void Print_cmnd ANSI((char *, int, int));
int Push_dir ANSI((char *, char *, int));
void Pop_dir ANSI((int));
void Append_line ANSI((char *, int, FILE *, char *, int, int));
void Stat_target ANSI((CELLPTR, int, int));
char *Expand ANSI((char *));
char *Apply_edit ANSI((char *, char *, char *, int, int));
void Map_esc ANSI((char *));
char* Apply_modifiers ANSI((int, char *));
char* Tokenize ANSI((char *, char *, char, int));
char* ScanToken ANSI((char *, char **, int));
char *DmStrJoin ANSI((char *, char *, int, int));
char *DmStrAdd ANSI((char *, char *, int));
char *DmStrApp ANSI((char *, char *));
char *DmStrDup ANSI((char *));
char *DmStrDup2 ANSI((char *));
char *DmStrPbrk ANSI((char *, char *));
char *DmStrSpn ANSI((char *, char *));
char *DmStrStr ANSI((char *, char *));
char *DmSubStr ANSI((char *, char *));
uint16 Hash ANSI((char *, uint32 *));
HASHPTR Get_name ANSI((char *, HASHPTR *, int));
HASHPTR Search_table ANSI((HASHPTR *, char *, uint16 *, uint32 *));
HASHPTR Push_macro ANSI((HASHPTR));
HASHPTR Pop_macro ANSI((HASHPTR));
HASHPTR Def_macro ANSI((char *, char *, int));
CELLPTR Def_cell ANSI((char *));
LINKPTR Add_prerequisite ANSI((CELLPTR, CELLPTR, int, int));
void Clear_prerequisites ANSI((CELLPTR));
int Test_circle ANSI((CELLPTR, int));
STRINGPTR Def_recipe ANSI((char *, STRINGPTR, int, int));
t_attr Rcp_attribute ANSI((char *));
int main ANSI((int, char **));
FILE *Openfile ANSI((char *, int, int));
FILE *Closefile ANSI(());
FILE *Search_file ANSI((char *, char **));
char *Filename ANSI(());
int Nestlevel ANSI(());
FILE *TryFiles ANSI((LINKPTR));
void Fatal ANSI((ARG (char *,fmt),ARG (va_alist_type, va_alist)));
void Error ANSI((ARG (char *,fmt),ARG (va_alist_type, va_alist)));
void Warning ANSI((ARG (char *,fmt),ARG (va_alist_type, va_alist)));
void No_ram ANSI(());
void Usage ANSI((int));
void Version ANSI(());
char *Get_suffix ANSI((char *));
char *Basename ANSI((char *));
char *Filedir ANSI((char *));
char *Build_path ANSI((char *, char *));
void Make_rules ANSI(());
void Create_macro_vars ANSI(());
time_t Do_stat ANSI((char *, char *, int));
int Do_touch ANSI((char *, char *));
void Void_lib_cache ANSI((char *, char *));
time_t Do_time ANSI(());
void Do_profile_output ANSI((char *, uint16, CELLPTR));
int Do_cmnd ANSI((char **, int, int, CELLPTR, t_attr, int));
char ** Pack_argv ANSI((int, int, char **));
char *Read_env_string ANSI((char *));
int Write_env_string ANSI((char *, char *));
void ReadEnvironment ANSI(());
void Catch_signals ANSI((void (*)(int)));
void Clear_signals ANSI(());
void Prolog ANSI((int, char* []));
void Epilog ANSI((int));
char *Get_current_dir ANSI(());
int Set_dir ANSI((char*));
char Get_switch_char ANSI(());
FILE* Get_temp ANSI((char **, char *));
FILE *Start_temp ANSI((char *, CELLPTR, char **));
void Open_temp_error ANSI((char *, char *));
void Link_temp ANSI((CELLPTR, FILE *, char *));
void Close_temp ANSI((CELLPTR, FILE *));
void Unlink_temp_files ANSI((CELLPTR));
void Handle_result ANSI((int, int, int, CELLPTR));
void Update_time_stamp ANSI((CELLPTR));
int Remove_file ANSI((char *));
void Parse ANSI((FILE *));
int Get_line ANSI((char *, FILE *));
char *Do_comment ANSI((char *, char **, int));
char *Get_token ANSI((TKSTRPTR, char *, int));
void Quit ANSI((int));
void Read_state ANSI(());
void Write_state ANSI(());
int Check_state ANSI((CELLPTR, STRINGPTR *, int));
void Dump ANSI(());
void Dump_recipe ANSI((STRINGPTR));
int Parse_macro ANSI((char *, int));
int Macro_op ANSI((char *));
int Parse_rule_def ANSI((int *));
int Rule_op ANSI((char *));
void Add_recipe_to_list ANSI((char *, int, int));
void Bind_rules_to_targets ANSI((int));
int Set_group_attributes ANSI((char *));
DFALINKPTR Match_dfa ANSI((char *));
void Check_circle_dfa ANSI(());
void Add_nfa ANSI((char *));
char *Exec_function ANSI((char *));
time_t seek_arch ANSI((char *, char *));
int touch_arch ANSI(( char *, char *));
void void_lcache ANSI(( char *, char *));
int If_root_path ANSI((char *));
void Remove_prq ANSI((CELLPTR));
int runargv ANSI((CELLPTR, int, int, t_attr, char **));
int Wait_for_child ANSI((int, int));
void Clean_up_processes ANSI(());
time_t CacheStat ANSI((char *, int));

#endif
