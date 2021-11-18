#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/IIR_LPFilter.x.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/IIR_LPFilter.x.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c ../blink_led_demo_dspic33ch.X/pps.c ../blink_led_demo_dspic33ch.X/gpio.c IIR_LPFilter.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/1696427052/pps.o ${OBJECTDIR}/_ext/1696427052/gpio.o ${OBJECTDIR}/IIR_LPFilter.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/_ext/1696427052/pps.o.d ${OBJECTDIR}/_ext/1696427052/gpio.o.d ${OBJECTDIR}/IIR_LPFilter.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/1696427052/pps.o ${OBJECTDIR}/_ext/1696427052/gpio.o ${OBJECTDIR}/IIR_LPFilter.o

# Source Files
SOURCEFILES=main.c ../blink_led_demo_dspic33ch.X/pps.c ../blink_led_demo_dspic33ch.X/gpio.c IIR_LPFilter.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/IIR_LPFilter.x.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33CH512MP506
MP_LINKER_FILE_OPTION=,--script=p33CH512MP506.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/3c427c93b38bb7d3f1013449d89c80496e785f32 .generated_files/flags/default/c39017f4fda401a6f44cc2e27e55d84559012e1d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1696427052/pps.o: ../blink_led_demo_dspic33ch.X/pps.c  .generated_files/flags/default/8c6ecb2053952fbf54e83e7375144261daf6b852 .generated_files/flags/default/c39017f4fda401a6f44cc2e27e55d84559012e1d
	@${MKDIR} "${OBJECTDIR}/_ext/1696427052" 
	@${RM} ${OBJECTDIR}/_ext/1696427052/pps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1696427052/pps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../blink_led_demo_dspic33ch.X/pps.c  -o ${OBJECTDIR}/_ext/1696427052/pps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1696427052/pps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1696427052/gpio.o: ../blink_led_demo_dspic33ch.X/gpio.c  .generated_files/flags/default/261127e9d52f189f8b68740f600556a8fa05868e .generated_files/flags/default/c39017f4fda401a6f44cc2e27e55d84559012e1d
	@${MKDIR} "${OBJECTDIR}/_ext/1696427052" 
	@${RM} ${OBJECTDIR}/_ext/1696427052/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1696427052/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../blink_led_demo_dspic33ch.X/gpio.c  -o ${OBJECTDIR}/_ext/1696427052/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1696427052/gpio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/IIR_LPFilter.o: IIR_LPFilter.c  .generated_files/flags/default/3778db8c8a96b73e11f1175f3d908594a1472d17 .generated_files/flags/default/c39017f4fda401a6f44cc2e27e55d84559012e1d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IIR_LPFilter.o.d 
	@${RM} ${OBJECTDIR}/IIR_LPFilter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  IIR_LPFilter.c  -o ${OBJECTDIR}/IIR_LPFilter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/IIR_LPFilter.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/4a3f5d420e434752762337ae0489e1a81b1dd82d .generated_files/flags/default/c39017f4fda401a6f44cc2e27e55d84559012e1d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1696427052/pps.o: ../blink_led_demo_dspic33ch.X/pps.c  .generated_files/flags/default/8c21828bc2caf354b5fa9c8dabfef59f69e8a4bc .generated_files/flags/default/c39017f4fda401a6f44cc2e27e55d84559012e1d
	@${MKDIR} "${OBJECTDIR}/_ext/1696427052" 
	@${RM} ${OBJECTDIR}/_ext/1696427052/pps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1696427052/pps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../blink_led_demo_dspic33ch.X/pps.c  -o ${OBJECTDIR}/_ext/1696427052/pps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1696427052/pps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1696427052/gpio.o: ../blink_led_demo_dspic33ch.X/gpio.c  .generated_files/flags/default/dc3d5db437f9252880b94427c42b93406a094abf .generated_files/flags/default/c39017f4fda401a6f44cc2e27e55d84559012e1d
	@${MKDIR} "${OBJECTDIR}/_ext/1696427052" 
	@${RM} ${OBJECTDIR}/_ext/1696427052/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1696427052/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../blink_led_demo_dspic33ch.X/gpio.c  -o ${OBJECTDIR}/_ext/1696427052/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1696427052/gpio.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/IIR_LPFilter.o: IIR_LPFilter.c  .generated_files/flags/default/d4738dab343abbb83018a0995174ec2d9acf9900 .generated_files/flags/default/c39017f4fda401a6f44cc2e27e55d84559012e1d
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IIR_LPFilter.o.d 
	@${RM} ${OBJECTDIR}/IIR_LPFilter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  IIR_LPFilter.c  -o ${OBJECTDIR}/IIR_LPFilter.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/IIR_LPFilter.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/IIR_LPFilter.x.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/IIR_LPFilter.x.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/IIR_LPFilter.x.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/IIR_LPFilter.x.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/IIR_LPFilter.x.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
