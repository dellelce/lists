
#
# Lists, 2016 by Antonio Dell'elce, antonio@dellelce.com
#

CC             = gcc
TARGET         = liblists.a

SHELL          = bash

CFILES         = src/add_empty_tail.c src/add_head.c src/add_node_after.c src/add_tail.c src/del_all_list.c src/del_list.c src/del_node.c src/del_tail.c src/new_list.c src/new_node.c src/scan_list.c src/scan_list2.c src/seg_free_node.c
OFILES         = obj/add_empty_tail.o obj/add_head.o obj/add_node_after.o obj/add_tail.o obj/del_all_list.o obj/del_list.o obj/del_node.o obj/del_tail.o obj/new_list.o obj/new_node.o obj/scan_list.o obj/scan_list2.o obj/seg_free_node.o
LDFLAGS	       = 


LOC_HFILES     = 
HFILES         = $(LOC_HFILES)

INCLUDES       =  -Iincludes
DEBUG          = 
CFLAGS         = -Wall -O2  $(INCLUDES) $(DEBUG)
LIBS           = 


#
# --- RULES ---
#

all:  $(TARGET) 

$(TARGET): $(OFILES)
	$(AR) rv $(TARGET) $(OFILES)

#
# -- DEPS --
#

obj/add_empty_tail.o: src/add_empty_tail.c $(HFILES) includes/lists.h
	@echo "CC "src/add_empty_tail.c
	@$(CC) -c $(CFLAGS) -o obj/add_empty_tail.o src/add_empty_tail.c

obj/add_head.o: src/add_head.c $(HFILES) includes/lists.h
	@echo "CC "src/add_head.c
	@$(CC) -c $(CFLAGS) -o obj/add_head.o src/add_head.c

obj/add_node_after.o: src/add_node_after.c $(HFILES) includes/lists.h
	@echo "CC "src/add_node_after.c
	@$(CC) -c $(CFLAGS) -o obj/add_node_after.o src/add_node_after.c

obj/add_tail.o: src/add_tail.c $(HFILES) includes/lists.h
	@echo "CC "src/add_tail.c
	@$(CC) -c $(CFLAGS) -o obj/add_tail.o src/add_tail.c

obj/del_all_list.o: src/del_all_list.c $(HFILES) includes/lists.h
	@echo "CC "src/del_all_list.c
	@$(CC) -c $(CFLAGS) -o obj/del_all_list.o src/del_all_list.c

obj/del_list.o: src/del_list.c $(HFILES) includes/lists.h
	@echo "CC "src/del_list.c
	@$(CC) -c $(CFLAGS) -o obj/del_list.o src/del_list.c

obj/del_node.o: src/del_node.c $(HFILES) includes/lists.h
	@echo "CC "src/del_node.c
	@$(CC) -c $(CFLAGS) -o obj/del_node.o src/del_node.c

obj/del_tail.o: src/del_tail.c $(HFILES) includes/lists.h
	@echo "CC "src/del_tail.c
	@$(CC) -c $(CFLAGS) -o obj/del_tail.o src/del_tail.c

obj/new_list.o: src/new_list.c $(HFILES) includes/lists.h
	@echo "CC "src/new_list.c
	@$(CC) -c $(CFLAGS) -o obj/new_list.o src/new_list.c

obj/new_node.o: src/new_node.c $(HFILES) includes/lists.h
	@echo "CC "src/new_node.c
	@$(CC) -c $(CFLAGS) -o obj/new_node.o src/new_node.c

obj/scan_list.o: src/scan_list.c $(HFILES) includes/lists.h
	@echo "CC "src/scan_list.c
	@$(CC) -c $(CFLAGS) -o obj/scan_list.o src/scan_list.c

obj/scan_list2.o: src/scan_list2.c $(HFILES) includes/lists.h
	@echo "CC "src/scan_list2.c
	@$(CC) -c $(CFLAGS) -o obj/scan_list2.o src/scan_list2.c

obj/seg_free_node.o: src/seg_free_node.c $(HFILES) includes/lists.h
	@echo "CC "src/seg_free_node.c
	@$(CC) -c $(CFLAGS) -o obj/seg_free_node.o src/seg_free_node.c

 
#  
# clean
#    
     
clean:
	rm -f $(TARGET) $(OFILES) $(LOC_HFILES) *.exe

#
# redo
#

redo: clean all

