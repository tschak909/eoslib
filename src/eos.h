/**
 * The Adam EOS C binding
 *
 * @author Thomas Cherryhomes
 * @email <thom.cherryhomes@gmail.com>
 */

#ifndef EOS_H
#define EOS_H

#define EOS_FILENAME_LEN 12

/* MIOC Bank Configurations */
#define BANK_CONFIG_SMARTWRITER_ROM_NORMAL_RAM 0
#define BANK_CONFIG_NORMAL_RAM_NORMAL_RAM 1
#define BANK_CONFIG_EXPANSION_RAM_NORMAL_RAM 2
#define BANK_CONFIG_OS7_ROM_NORMAL_RAM 3
#define BANK_CONFIG_SMARTWRITER_ROM_EXPANSION_ROM 4
#define BANK_CONFIG_NORMAL_RAM_EXPANSION_ROM 5
#define BANK_CONFIG_EXPANSION_RAM_EXPANSION_ROM 6
#define BANK_CONFIG_OS7_RAM_EXPANSION_ROM 7
#define BANK_CONFIG_SMARTWRITER_ROM_EXPANSION_RAM 8
#define BANK_CONFIG_NORMAL_RAM_EXPANSION_RAM 9
#define BANK_CONFIG_EXPANSION_RAM_EXPANSION_RAM 10
#define BANK_CONFIG_OS7_EXPANSION_RAM 11
#define BANK_CONFIG_SMARTWRITER_ROM_CARTRIDGE_ROM 12
#define BANK_CONFIG_NORMAL_RAM_CARTRIDGE_ROM 13
#define BANK_CONFIG_EXPANSION_RAM_CARTRIDGE_ROM 14
#define BANK_CONFIG_OS7_ROM_CARTRIDGE_ROM 15

/* VDP table numbers */
#define VDP_TABLE_SPRITE_ATTRIBUTE 0
#define VDP_TABLE_SPRITE_PATTERN 1
#define VDP_TABLE_PATTERN_NAMETABLE 2
#define VDP_TABLE_PATTERN_GENERATOR 3
#define VDP_TABLE_PATTERN_COLOR 4

typedef struct _dcb
{
  unsigned char status;
  void *buf;
  unsigned short len;
  unsigned long block;
  unsigned char unit;
  unsigned long reserved;
  unsigned short retry_count;
  unsigned char dev;
  unsigned short max_len;
  unsigned char type;
  unsigned char dev_status;
} DCB;

/* EOS File Control Block (FCB) structure */
typedef struct _fcb
{
  char filename[EOS_FILENAME_LEN];
  unsigned char attributes;
  unsigned long start_block;
  unsigned short allocated_blocks;
  unsigned short used_blocks;
  unsigned short last_block_bytes_used;
  unsigned char dev;
  unsigned char file_mode;
  unsigned short current_block;
  unsigned short last_block;
  unsigned short block_pos;
  unsigned char fcb_len;
} FCB;

/* EOS directory entry */
typedef struct _directoryEntry
{
  char filename[EOS_FILENAME_LEN];
  unsigned char attributes;
  unsigned long start_block;
  unsigned short allocated_blocks;
  unsigned short blocks_used;
  unsigned short last_block_bytes_used;
  unsigned char year;
  unsigned char month;
  unsigned char day;
} DirectoryEntry;

typedef struct _fileManager
{
  unsigned char year;
  unsigned char month;
  unsigned char dday;
  DirectoryEntry currentEntry;
  FCB *fcb;
  void *dir_buf; // TODO: get structure of this buffer?
  unsigned char file_number;
  unsigned short bytes_requested;
  unsigned short bytes_to_process;
  void *user_buf;
  void *fcb_begin;
  void *fcb_end;
  unsigned long current_block;
  char* filename;
  unsigned long blockno;
  unsigned long start_of_blocks_left;
  unsigned short blocks_left;
} FileManager;
  
#endif /* EOS_H */
