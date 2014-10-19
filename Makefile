CXX := g++
CXXFLAGS := -Wall -O2 -Wno-deprecated
CXXFLAGS += -std=c++0x
BUILDDIR := build
OUTPUTDIR := release
SRCEXT := cpp

APPNAME := assign2
APPEXT := exe
LIBNAME = SmartHomeSDK
LIBEXT := so
LIBDIR := SHAPI
INCLDIR := SHAPI

CXXFLAGS += $(addprefix -I,$(INCLDIR))

TARGET := $(OUTPUTDIR)/$(APPNAME).$(APPEXT)
LDFLAGS := -o -Wl
SHAPILIB := $(LIBDIR)/$(LIBNAME).$(LIBEXT)
LIBS := $(SHAPILIB) -lpthread

SOURCES := assign2.cpp SystemHandler.cpp BuildingManager.cpp FloorManager.cpp BuildingUI.cpp FloorUI.cpp BaseUI.cpp BuildingModel.cpp FloorModel.cpp NamedEntity.cpp RoomModel.cpp
OBJECTS := $(addprefix $(BUILDDIR)/,$(SOURCES:.$(SRCEXT)=.o))
DEPS := $(OBJECTS:.o=.deps)

default: $(TARGET)
 
$(TARGET): $(OBJECTS)

	@mkdir -p $(OUTPUTDIR)	
	@cp $(SHAPILIB) $(OUTPUTDIR)
	@echo " Linking..."; $(CXX) $(LDFLAGS) $^ -o $(TARGET) $(LIBS) 
 
$(BUILDDIR)/%.o: %.$(SRCEXT)

	@mkdir -p $(BUILDDIR)
	@echo " CXX $<"; $(CC) $(CXXFLAGS) -MD -MF $(@:.o=.deps) -c -o $@ $<

clean:

	@echo " Cleaning..."; $(RM) -rf $(BUILDDIR) $(OUTPUTDIR)	
 
-include $(DEPS)
 
.PHONY: clean
