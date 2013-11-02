# OK - final READY TO USE
# Working. 
# Seems to be the best because all .o are stored at the same root dir, and this is easy to remove it.
# 
# 

## headers subdirs
#IDIRS = -I./display -I./sensor -I./timer -I./sys
#
##CC=gcc   
##CFLAGS=-c -Wall $(IDIRS) 
#
#CXX=g++
#CXXFLAGS=-c -Wall $(IDIRS) 
#
#LDFLAGS=
#LDLIBS=
#
## all source subdirs for linker and compilator
#VPATH = display sensor timer
#
#all : v_pc.exe
#
#v_pc.exe : Display.o DisplaySDL.o BMP085Sensor.o Timer.o v_pc.o 
#	$(CXX) -o v_pc.exe Display.o DisplaySDL.o BMP085Sensor.o Timer.o v_pc.o
#
#










# 131020
# Check this one as well. It should be universal, from www.elitecoders.de by George Foot
# http://www.elitecoders.de/mags/cscene/CS2/CS2-10.html
#
#
######################################
#                                    #
#          Generic makefile          #
#                                    #
#           by George Foot           #
# email: george.foot@merton.ox.ac.uk #
#                                    #
#   Copyright (c) 1997 George Foot   #
#        All rights reserved.        #
#                                    #
#     No warranty, no liability;     #
#   you use this at your own risk.   #
#                                    #
#     You are free to modify and     #
#   distribute this without giving   #
#   credit to the original author.   #
#                                    #
######################################

# The targets of this makefile (which can be passed on the command line to select them) are:
#
# everything (default): Update the main executable, also creating or updating a `.d' file
#                       and a `.o' file for each source file.
#
# deps: Just create/update a `.d' file for each source file.
#
# objs: Create/update the `.d' files and the object files for each source file.
#
# clean: Delete all the intermediate/dependency files (*.d and *.o).
#
# veryclean: Do `clean' and also delete the executable.
#
# rebuild: Do `veryclean' and `everything'; i.e. rebuild from scratch
#
# Of these, clean, veryclean and rebuild are the only really useful ones apart from the default
# of everything.

### Customising
#
# Adjust the following if necessary; EXECUTABLE is the target
# executable's filename, and LIBS is a list of libraries to link in
# (e.g. alleg, stdcx, iostr, etc). You can override these on make's
# command line of course, if you prefer to do it that way.

CXX=g++

#EXECUTABLE := mushroom.exe
EXECUTABLE := v_pc.exe
#LIBS := alleg
LIBS := 

# try to automate it
IDIRS = -I./ui -I./ui/display -I./ui/kbd -I./ui/sound  -I./sensor -I./timer -I./sys

# Now alter any implicit rules' variables if you like, e.g.:

#CFLAGS := -g -Wall -O3 -m486
CFLAGS := -c -Wall $(IDIRS)
CXXFLAGS := $(CFLAGS)

# The next bit checks to see whether rm is in your djgpp bin
# directory; if not it uses del instead, but this can cause (harmless)
# `File not found' error messages. If you are not using DOS at all,
# set the variable to something which will unquestioningly remove
# files.

#ifneq ($(wildcard $(DJDIR)/bin/rm.exe),)
#RM-F := rm -f
#else
#RM-F := del
#endif
RM-F := rm -f


# You shouldn't need to change anything below this point.

SOURCE := $(wildcard *.c) $(wildcard *.cpp)
OBJS := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))
DEPS := $(patsubst %.o,%.d,$(OBJS))
MISSING_DEPS := $(filter-out $(wildcard $(DEPS)),$(DEPS))
MISSING_DEPS_SOURCES := $(wildcard $(patsubst %.d,%.c,$(MISSING_DEPS)) \
                                   $(patsubst %.d,%.cpp,$(MISSING_DEPS)))
CPPFLAGS += -MD

.PHONY : everything deps objs clean veryclean rebuild

everything : $(EXECUTABLE)

deps : $(DEPS)

objs : $(OBJS)

clean :
	@$(RM-F) *.o
	@$(RM-F) *.d

veryclean: clean
	@$(RM-F) $(EXECUTABLE)

rebuild: veryclean everything

ifneq ($(MISSING_DEPS),)
$(MISSING_DEPS) :
	@$(RM-F) $(patsubst %.d,%.o,$@)
endif

-include $(DEPS)

#$(EXECUTABLE) : $(OBJS)
#	gcc -o $(EXECUTABLE) $(OBJS) $(addprefix -l,$(LIBS))

$(EXECUTABLE) : $(OBJS)
	$(CXX) -o $(EXECUTABLE) $(OBJS) $(addprefix -l,$(LIBS))


