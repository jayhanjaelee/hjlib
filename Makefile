CC = clang
CFLAGS = -Wall -Iinclude

BUILD_DIR = build

TARGET = libhjlib.a

SRCS = $(shell find src -name '*.c')
OBJECTS = $(patsubst src/%.c, build/obj/%.o, $(SRCS))

all: $(OBJECTS)

build/obj/%.o : src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -MD

install: $(OBJECTS)
	@mkdir -p $(BUILD_DIR)
	ar rcs $(BUILD_DIR)/$(TARGET) $(OBJECTS)
	@mkdir -p /usr/local/include/hjlib
	cp -r include/* /usr/local/include/hjlib
	cp build/$(TARGET) /usr/local/lib

uninstall:
	rm -rf /usr/local/include/hjlib
	rm -f /usr/local/lib/$(TARGET)

test:
	# $(CC) -Iinclude -Lbuild -lhjlib -o build/test test.c
	$(CC) -I/usr/local/include -L/usr/local/lib -lhjlib -o build/test test.c
	build/test

PHONY: clean

clean:
	@rm -rf build

print:
	@echo "SRCS:" $(SRCS)
	@echo "OBJECTS:" $(OBJECTS)
