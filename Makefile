CXX_LINUX = g++
CXX_WIN = x86_64-w64-mingw32-g++
# CXXFLAGS_WARNINGS = -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror
CXXFLAGS = $(CXXFLAGS_WARNINGS) -std=c++23 -g
CXXFLAGS_WIN = $(CXXFLAGS) -static
INCDIR = include
TARGET = temp
SRCDIR = src
OBJDIR = obj
BINDIR = bin

LIBS_LINUX += -lpthread
# LIBS_WIN += -lglfw3 -lopengl32 -lgdi32

SRCS = $(wildcard $(SRCDIR)/*.cpp)

OBJS_LINUX = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/linux/%.o,$(SRCS))
OBJS_WIN = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/win/%.o,$(SRCS))

VCPKG_DIR = /home/x/vcpkg
CXXFLAGS += -I$(VCPKG_DIR)/installed/x64-linux/include
CXXFLAGS += -I$(VCPKG_DIR)/installed/x64-mingw-static/include
LDFLAGS_LINUX += -L$(VCPKG_DIR)/installed/x64-linux/lib
LDFLAGS_WIN += -L$(VCPKG_DIR)/installed/x64-mingw-static/lib

BUILD_WIN ?= 0

ifeq ($(BUILD_WIN),1)
all: linux windows
else
all: linux
endif

linux: $(BINDIR)/$(TARGET)

windows: $(BINDIR)/$(TARGET).exe

win:
	$(MAKE) BUILD_WIN=1

$(BINDIR)/$(TARGET): $(OBJS_LINUX) | $(BINDIR)
	 $(CXX_LINUX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS_LINUX) $(LIBS_LINUX)

$(BINDIR)/$(TARGET).exe: $(OBJS_WIN) | $(BINDIR)
	$(CXX_WIN) $(CXXFLAGS_WIN) -o $@ $^ $(LDFLAGS_WIN) $(LIBS_WIN)

$(OBJDIR)/linux/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)/linux
	$(CXX_LINUX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/win/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)/win
	$(CXX_WIN) $(CXXFLAGS_WIN) -c $< -o $@

$(OBJDIR)/linux $(OBJDIR)/win $(BINDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)
