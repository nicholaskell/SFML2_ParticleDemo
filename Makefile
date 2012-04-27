
SRC_DIR=src/

OBJDIR=$(SRC_DIR)_nv_obj/

EXECUTABLE_NAME=sample.bin

COMPILE_VERSION_MAJOR = 0
COMPILE_VERSION_MINOR = 0
COMPILE_VERSION_REVISION = "undefined in makefile"

SDL_LIBRARIES = -lSDL_image -lSDL_mixer -lSDL -lSDL_ttf
SFML_LIBRARIES = -lsfml-system -lsfml-window -lsfml-network -lsfml-graphics -lsfml-audio
MEDIA_LIBRARIES = $(SFML_LIBRARIES)
LIBRARIES = $(MEDIA_LIBRARIES) -lcups -lserial -ldl -lm





MKDIR_P=mkdir -p
UNAME:=$(shell uname -s)

CPP_SOURCES:=$(shell find $(SRC_DIR) -type f -name '*.cpp')
CPP_OBJECTS=$(CPP_SOURCES:%.cpp=$(OBJDIR)%.o) 
OBJECTS=$(CPP_OBJECTS)

CPP_ONLY_WARNING_FLAGS:=  -Wsign-compare
WARNING_FLAGS_NO_WARNINGS:= -w
WARNING_FLAGS_ALL_WARNINGS:= -Wall

WARNING_FLAGS := $(CPP_ONLY_WARNING_FLAGS) -Wunreachable-code

# -O0 is the default Optimization flag
OPTIMIZE_FLAGS:= -O0 

CPP_C = g++
CPP_LINK_FLAGS = -g -o
CPP_FLAGS = 



LINKER_EXTRAS =
COMPILER_EXTRAS =
#LIBRARIES =  -lSDL_image -lSDL_mixer -lSDL -lSDL_ttf -lcups -lserial -ldl -lm


VERSION_DEFINES:= -D VERSION_MAJOR=$(COMPILE_VERSION_MAJOR) -D VERSION_MINOR=$(COMPILE_VERSION_MINOR) -D VERSION_REVISION=$(COMPILE_VERSION_REVISION)


COMPILE_DATE:= `date +'%y.%m.%d'`
COMPILE_TIME:= `date +'%H:%M:%S'`
COMPILE_DATE_TIME_DEFINES:= -D COMPILE_DATE=$(COMPILE_DATE) -D COMPILE_TIME=$(COMPILE_TIME)

EXECUTABLE?= $(EXECUTABLE_NAME)
DEFINES := $(VERSION_DEFINES) $(COMPILE_DATE_TIME_DEFINES)
COMPILER_FLAGS = -c -g $(OPTIMIZE_FLAGS)



all: $(OBJECTS)
	@echo -n 'Start executable linking.....'
	@if $(CPP_C) $(CPP_LINK_FLAGS) $(EXECUTABLE) $(DEFINES) $(OBJECTS) $(LINKER_EXTRAS) $(LIBRARIES) ;\
	then printf "SUCCESS!!\t\t\t";echo '';echo '-- Produced: '$(EXECUTABLE); echo '';\
	else echo ''; echo "FAIL"; echo ''; exit 1;\
	fi


$(OBJDIR)%.o : %.cpp
	@$(MKDIR_P) $(@D)
	@printf '%s' 'Compiling $*.cpp....'
	@if g++ -Wno-deprecated  $(DEFINES) $(COMPILER_FLAGS) $(COMPILER_EXTRAS) -I ./$(SRC_DIR) $< -o $@;\
	then echo "Success";\
	else echo "FAIL"; echo ''; exit 1;\
	fi


.PHONY: 	clean done start nick v_colonFile checkosx scrub
.IGNORE: 	clean

clean:
	@echo '';echo '';echo '';
	@echo  "Starting the clean."
	-rm  $(OBJECTS) $(EXECUTABLE)
	@echo "cleaned up."
	@echo '';echo '';echo 'Files left behind:';
	ls -R $(OBJDIR) | grep "\.o"



done:
	@echo '';echo '';echo '';
	
start:
	clear;
	@echo '';echo '';echo '';
	@echo 'Start.'; 

scrub: start clean all done



