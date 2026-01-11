###########################################################################
## Makefile generated for component 'my_qdprog'. 
## 
## Makefile     : my_qdprog_rtw.mk
## Generated on : Sat Jan 10 02:02:50 2026
## Final product: ./my_qdprog.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = my_qdprog
MAKEFILE                  = my_qdprog_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2024b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2024b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/Brighton/Desktop/mat
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = my_qdprog_rtw_comp.rsp
CMD_FILE                  = my_qdprog_rtw.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = my_qdprog.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    8.x
# ToolchainInfo Version:   2024b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align -Wno-stringop-overflow
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align -Wno-stringop-overflow
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = $(MINGW_ROOT)
MAKE = "$(MAKE_PATH)/mingw32-make.exe"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O3
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O3
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -j $(MAX_MAKE_JOBS) -l $(MAX_MAKE_LOAD_AVG) -Oline -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./my_qdprog.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__USE_MINGW_ANSI_STDIO=1
DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=my_qdprog

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/my_qdprog/my_qdprog_data.cpp $(START_DIR)/codegen/lib/my_qdprog/rt_nonfinite.cpp $(START_DIR)/codegen/lib/my_qdprog/rtGetNaN.cpp $(START_DIR)/codegen/lib/my_qdprog/rtGetInf.cpp $(START_DIR)/codegen/lib/my_qdprog/my_qdprog_initialize.cpp $(START_DIR)/codegen/lib/my_qdprog/my_qdprog_terminate.cpp $(START_DIR)/codegen/lib/my_qdprog/my_qdprog.cpp $(START_DIR)/codegen/lib/my_qdprog/xnrm2.cpp $(START_DIR)/codegen/lib/my_qdprog/quadprog.cpp $(START_DIR)/codegen/lib/my_qdprog/loadProblem.cpp $(START_DIR)/codegen/lib/my_qdprog/setProblemType.cpp $(START_DIR)/codegen/lib/my_qdprog/modifyOverheadPhaseOne_.cpp $(START_DIR)/codegen/lib/my_qdprog/xgeqp3.cpp $(START_DIR)/codegen/lib/my_qdprog/xzlarfg.cpp $(START_DIR)/codegen/lib/my_qdprog/xzlarf.cpp $(START_DIR)/codegen/lib/my_qdprog/driver.cpp $(START_DIR)/codegen/lib/my_qdprog/PresolveWorkingSet.cpp $(START_DIR)/codegen/lib/my_qdprog/RemoveDependentEq_.cpp $(START_DIR)/codegen/lib/my_qdprog/ComputeNumDependentEq_.cpp $(START_DIR)/codegen/lib/my_qdprog/computeQ_.cpp $(START_DIR)/codegen/lib/my_qdprog/countsort.cpp $(START_DIR)/codegen/lib/my_qdprog/removeEqConstr.cpp $(START_DIR)/codegen/lib/my_qdprog/removeConstr.cpp $(START_DIR)/codegen/lib/my_qdprog/RemoveDependentIneq_.cpp $(START_DIR)/codegen/lib/my_qdprog/feasibleX0ForWorkingSet.cpp $(START_DIR)/codegen/lib/my_qdprog/maxConstraintViolation.cpp $(START_DIR)/codegen/lib/my_qdprog/phaseone.cpp $(START_DIR)/codegen/lib/my_qdprog/iterate.cpp $(START_DIR)/codegen/lib/my_qdprog/computeGrad_StoreHx.cpp $(START_DIR)/codegen/lib/my_qdprog/computeFval_ReuseHx.cpp $(START_DIR)/codegen/lib/my_qdprog/squareQ_appendCol.cpp $(START_DIR)/codegen/lib/my_qdprog/xrotg.cpp $(START_DIR)/codegen/lib/my_qdprog/deleteColMoveEnd.cpp $(START_DIR)/codegen/lib/my_qdprog/compute_deltax.cpp $(START_DIR)/codegen/lib/my_qdprog/compute_lambda.cpp $(START_DIR)/codegen/lib/my_qdprog/addAineqConstr.cpp $(START_DIR)/codegen/lib/my_qdprog/addBoundToActiveSetMatrix_.cpp $(START_DIR)/codegen/lib/my_qdprog/computeFval.cpp $(START_DIR)/codegen/lib/my_qdprog/linearForm_.cpp $(START_DIR)/codegen/lib/my_qdprog/computeFirstOrderOpt.cpp $(START_DIR)/codegen/lib/my_qdprog/xzgeqp3.cpp $(START_DIR)/codegen/lib/my_qdprog/xgemv.cpp $(START_DIR)/codegen/lib/my_qdprog/factorQR.cpp $(START_DIR)/codegen/lib/my_qdprog/fullColLDL2_.cpp $(START_DIR)/codegen/lib/my_qdprog/checkStoppingAndUpdateFval.cpp $(START_DIR)/codegen/lib/my_qdprog/feasibleratiotest.cpp $(START_DIR)/codegen/lib/my_qdprog/my_qdprog_rtwutil.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = my_qdprog_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj my_qdprog_initialize.obj my_qdprog_terminate.obj my_qdprog.obj xnrm2.obj quadprog.obj loadProblem.obj setProblemType.obj modifyOverheadPhaseOne_.obj xgeqp3.obj xzlarfg.obj xzlarf.obj driver.obj PresolveWorkingSet.obj RemoveDependentEq_.obj ComputeNumDependentEq_.obj computeQ_.obj countsort.obj removeEqConstr.obj removeConstr.obj RemoveDependentIneq_.obj feasibleX0ForWorkingSet.obj maxConstraintViolation.obj phaseone.obj iterate.obj computeGrad_StoreHx.obj computeFval_ReuseHx.obj squareQ_appendCol.obj xrotg.obj deleteColMoveEnd.obj compute_deltax.obj compute_lambda.obj addAineqConstr.obj addBoundToActiveSetMatrix_.obj computeFval.obj linearForm_.obj computeFirstOrderOpt.obj xzgeqp3.obj xgemv.obj factorQR.obj fullColLDL2_.obj checkStoppingAndUpdateFval.obj feasibleratiotest.obj my_qdprog_rtwutil.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_TFL = -msse2 -fno-predictive-commoning
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_TFL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_TFL = -msse2 -fno-predictive-commoning
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_TFL) $(CPPFLAGS_BASIC)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/my_qdprog/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/my_qdprog/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/my_qdprog/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/my_qdprog/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/my_qdprog/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/my_qdprog/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/my_qdprog/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/my_qdprog/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


my_qdprog_data.obj : $(START_DIR)/codegen/lib/my_qdprog/my_qdprog_data.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/codegen/lib/my_qdprog/rt_nonfinite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/codegen/lib/my_qdprog/rtGetNaN.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/codegen/lib/my_qdprog/rtGetInf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


my_qdprog_initialize.obj : $(START_DIR)/codegen/lib/my_qdprog/my_qdprog_initialize.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


my_qdprog_terminate.obj : $(START_DIR)/codegen/lib/my_qdprog/my_qdprog_terminate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


my_qdprog.obj : $(START_DIR)/codegen/lib/my_qdprog/my_qdprog.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xnrm2.obj : $(START_DIR)/codegen/lib/my_qdprog/xnrm2.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


quadprog.obj : $(START_DIR)/codegen/lib/my_qdprog/quadprog.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


loadProblem.obj : $(START_DIR)/codegen/lib/my_qdprog/loadProblem.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


setProblemType.obj : $(START_DIR)/codegen/lib/my_qdprog/setProblemType.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


modifyOverheadPhaseOne_.obj : $(START_DIR)/codegen/lib/my_qdprog/modifyOverheadPhaseOne_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgeqp3.obj : $(START_DIR)/codegen/lib/my_qdprog/xgeqp3.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlarfg.obj : $(START_DIR)/codegen/lib/my_qdprog/xzlarfg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzlarf.obj : $(START_DIR)/codegen/lib/my_qdprog/xzlarf.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


driver.obj : $(START_DIR)/codegen/lib/my_qdprog/driver.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


PresolveWorkingSet.obj : $(START_DIR)/codegen/lib/my_qdprog/PresolveWorkingSet.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


RemoveDependentEq_.obj : $(START_DIR)/codegen/lib/my_qdprog/RemoveDependentEq_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


ComputeNumDependentEq_.obj : $(START_DIR)/codegen/lib/my_qdprog/ComputeNumDependentEq_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeQ_.obj : $(START_DIR)/codegen/lib/my_qdprog/computeQ_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


countsort.obj : $(START_DIR)/codegen/lib/my_qdprog/countsort.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


removeEqConstr.obj : $(START_DIR)/codegen/lib/my_qdprog/removeEqConstr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


removeConstr.obj : $(START_DIR)/codegen/lib/my_qdprog/removeConstr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


RemoveDependentIneq_.obj : $(START_DIR)/codegen/lib/my_qdprog/RemoveDependentIneq_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


feasibleX0ForWorkingSet.obj : $(START_DIR)/codegen/lib/my_qdprog/feasibleX0ForWorkingSet.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


maxConstraintViolation.obj : $(START_DIR)/codegen/lib/my_qdprog/maxConstraintViolation.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


phaseone.obj : $(START_DIR)/codegen/lib/my_qdprog/phaseone.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


iterate.obj : $(START_DIR)/codegen/lib/my_qdprog/iterate.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeGrad_StoreHx.obj : $(START_DIR)/codegen/lib/my_qdprog/computeGrad_StoreHx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFval_ReuseHx.obj : $(START_DIR)/codegen/lib/my_qdprog/computeFval_ReuseHx.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


squareQ_appendCol.obj : $(START_DIR)/codegen/lib/my_qdprog/squareQ_appendCol.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xrotg.obj : $(START_DIR)/codegen/lib/my_qdprog/xrotg.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


deleteColMoveEnd.obj : $(START_DIR)/codegen/lib/my_qdprog/deleteColMoveEnd.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


compute_deltax.obj : $(START_DIR)/codegen/lib/my_qdprog/compute_deltax.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


compute_lambda.obj : $(START_DIR)/codegen/lib/my_qdprog/compute_lambda.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


addAineqConstr.obj : $(START_DIR)/codegen/lib/my_qdprog/addAineqConstr.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


addBoundToActiveSetMatrix_.obj : $(START_DIR)/codegen/lib/my_qdprog/addBoundToActiveSetMatrix_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFval.obj : $(START_DIR)/codegen/lib/my_qdprog/computeFval.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


linearForm_.obj : $(START_DIR)/codegen/lib/my_qdprog/linearForm_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


computeFirstOrderOpt.obj : $(START_DIR)/codegen/lib/my_qdprog/computeFirstOrderOpt.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xzgeqp3.obj : $(START_DIR)/codegen/lib/my_qdprog/xzgeqp3.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


xgemv.obj : $(START_DIR)/codegen/lib/my_qdprog/xgemv.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


factorQR.obj : $(START_DIR)/codegen/lib/my_qdprog/factorQR.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


fullColLDL2_.obj : $(START_DIR)/codegen/lib/my_qdprog/fullColLDL2_.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


checkStoppingAndUpdateFval.obj : $(START_DIR)/codegen/lib/my_qdprog/checkStoppingAndUpdateFval.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


feasibleratiotest.obj : $(START_DIR)/codegen/lib/my_qdprog/feasibleratiotest.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


my_qdprog_rtwutil.obj : $(START_DIR)/codegen/lib/my_qdprog/my_qdprog_rtwutil.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


