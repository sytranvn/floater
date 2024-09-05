TARGET	:= main
# OBJECTS	:= floater.o
FLAGS := -g
OBJ_DIR := obj
SRC_FILES := $(wildcard *.c)
OBJECTS := $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	cc ${FLAGS} $(OBJECTS) -o $(TARGET)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	rm $(OBJECTS) $(TARGET)
