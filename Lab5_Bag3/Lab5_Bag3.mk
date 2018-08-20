##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab5_Bag3
ConfigurationName      :=Debug
WorkspacePath          :=/Users/jasonwalters/Documents/KSU/DataStructures/DS3304
ProjectPath            :=/Users/jasonwalters/Documents/KSU/DataStructures/DS3304/Lab5_Bag3
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jason Walters
Date                   :=26/10/2017
CodeLitePath           :="/Users/jasonwalters/Library/Application Support/codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Lab5_Bag3.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/private/var/folders/bs/_gc8nw0s2dg8gvlpwqfw1hjw0000gn/T/AppTranslocation/AD057C8F-4592-4667-AD81-8AC5A1D43C60/d/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/bag3.cpp$(ObjectSuffix) $(IntermediateDirectory)/toolkit.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/jasonwalters/Documents/KSU/DataStructures/DS3304/Lab5_Bag3/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/bag3.cpp$(ObjectSuffix): bag3.cpp $(IntermediateDirectory)/bag3.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/jasonwalters/Documents/KSU/DataStructures/DS3304/Lab5_Bag3/bag3.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bag3.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bag3.cpp$(DependSuffix): bag3.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bag3.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/bag3.cpp$(DependSuffix) -MM bag3.cpp

$(IntermediateDirectory)/bag3.cpp$(PreprocessSuffix): bag3.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bag3.cpp$(PreprocessSuffix) bag3.cpp

$(IntermediateDirectory)/toolkit.cpp$(ObjectSuffix): toolkit.cpp $(IntermediateDirectory)/toolkit.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/jasonwalters/Documents/KSU/DataStructures/DS3304/Lab5_Bag3/toolkit.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/toolkit.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/toolkit.cpp$(DependSuffix): toolkit.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/toolkit.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/toolkit.cpp$(DependSuffix) -MM toolkit.cpp

$(IntermediateDirectory)/toolkit.cpp$(PreprocessSuffix): toolkit.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/toolkit.cpp$(PreprocessSuffix) toolkit.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


