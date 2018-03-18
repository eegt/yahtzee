TARGET = yahtzeetests
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall -I$(LIBSRCDIR)
OBJDIR = obj
LIBSRCDIR = ../Yahtzee

.PHONY: default all clean

all: copy $(TARGET)

OBJECTS = $(patsubst %.c, $(OBJDIR)/%.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

$(OBJDIR)/%.o: %.c $(HEADERS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f $(OBJDIR)/*.o
	-rm -f $(TARGET)

# Copies the most recent versions of source under test
# Not an elegant solution... better to link to libraries and
# run the tests automatically. For one thing, this gets the
# latest source, even if it's in an indeterminate state that
# doesn't build. But this gets us going for starters.
copy:
	cp $(LIBSRCDIR)/yahtzeeScoreChecker.c yahtzeeScoreChecker.c
	cp $(LIBSRCDIR)/yahtzeeScoreChecker.h yahtzeeScoreChecker.h
	cp $(LIBSRCDIR)/yahtzeeScorer.c yahtzeeScorer.c
	cp $(LIBSRCDIR)/yahtzeeScorer.h yahtzeeScorer.h
