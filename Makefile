SRC := $(SOURCE)
TARGET := $(SRC:.cpp=.sol)
OUTPUT := $(SRC:.cpp=.output)
SOURCE_DIR := $(shell dirname $(realpath $(SOURCE)))
INPUT := $(SOURCE_DIR)/input
ANSWER := $(SOURCE_DIR)/answer

CXX := g++
LDFLAGS := $(LDFLAGS) -lm #-lcrypt
CXXFLAGS := $(CXXFLAGS) -Wall -g -O2 -std=c++11 -pipe -DONLINE_JUDGE -I/usr/local/opt/openssl/include

.PHONY: run all clean

all: $(TARGET)

run: $(TARGET)
	@echo "\033[0;35m> Run $< \033[0m"
	@$< < $(INPUT) > $(OUTPUT)
	@if diff $(OUTPUT) $(ANSWER); then \
		echo "\033[92m> Pass ! \033[0m"; \
	else \
		echo "\033[0;31m> Fail ! \033[0m"; \
	fi

$(TARGET): $(SRC)
	@echo "\033[1;33m> Build $@ \033[0m"
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $<

clean:
	@rm $(TARGET) $(OUTPUT)
