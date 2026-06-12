# IMPORTANTE make (compila) e make run (compila e executa)

CXX      := g++
CXXFLAGS := -std=c++14 -Wall -Wextra -Iinclude
SRCDIR   := src
BUILDDIR := build
BINDIR   := $(BUILDDIR)/bin
OBJDIR   := $(BUILDDIR)/obj
TARGET   := $(BINDIR)/calculadora

# Coleta todos os .cpp de src/ e gera os respectivos .o em build/obj/.
SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS  := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

.PHONY: all run clean docs

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@
	@echo "==> Compilado: $(TARGET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	@./$(TARGET)

# Gera a documentacao Doxyge
	doxygen Doxyfile

clean:
	rm -rf $(OBJDIR) $(BINDIR)
	@echo "==> Limpeza concluida."
