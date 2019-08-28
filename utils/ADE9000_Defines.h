/*
 * ADE9000.h
 *
 *  Created on: 16 de abr de 2018
 *      Author: lolo
 */

#ifndef INC_ADE9000_H_
#define INC_ADE9000_H_

/**
 * @def Endereco dos Registros do ADE9000 - LEITURA DE PARAMETROS
 *
 * @brief Enderecos dos Registradores do ADE9000
 * @see Datasheet do ADE9000 - \git\...
 */
#define	AI_PCF			0x020A
#define	AV_PCF			0x020B
#define	AIRMS			0x020C
#define	AVRMS			0x020D
#define	AIFRMS			0x020E
#define	AVFRMS			0x020F
#define	AWATT			0x0210
#define	AVAR			0x0211
#define	AVA				0x0212
#define	AFWATT			0x0213
#define	AFVAR			0x0214
#define	AFVA			0x0215
#define	APF				0x0216
#define	AVTHD			0x0217
#define	AITHD			0x0218
#define	AIRMSONE		0x0219
#define	AVRMSONE		0x021A
#define	AIRMS1012		0x021B
#define	AVRMS1012		0x021C

#define	BI_PCF			0x022A
#define	BV_PCF			0x022B
#define	BIRMS			0x022C
#define	BVRMS			0x022D
#define	BIFRMS			0x022E
#define	BVFRMS			0x022F
#define	BWATT			0x0230
#define	BVAR			0x0231
#define	BVA				0x0232
#define	BFWATT			0x0233
#define	BFVAR			0x0234
#define	BFVA			0x0235
#define	BPF				0x0236
#define	BVTHD			0x0237
#define	BITHD			0x0238
#define	BIRMSONE		0x0239
#define	BVRMSONE		0x023A
#define	BIRMS1012		0x023B
#define	BVRMS1012		0x023C

#define	CI_PCF			0x024A
#define	CV_PCF			0x024B
#define	CIRMS			0x024C
#define	CVRMS			0x024D
#define	CIFRMS			0x024E
#define	CVFRMS			0x024F
#define	CWATT			0x0250
#define	CVAR			0x0251
#define	CVA				0x0252
#define	CFWATT			0x0253
#define	CFVAR			0x0254
#define	CFVA			0x0255
#define	CPF				0x0256
#define	CVTHD			0x0257
#define	CITHD			0x0258
#define	CIRMSONE		0x0259
#define	CVRMSONE		0x025A
#define	CIRMS1012		0x025B
#define	CVRMS1012		0x025C

#define	NI_PCF			0x0265
#define	NIRMS			0x0266
#define	NIRMSONE		0x0267
#define	NIRMS1012		0x0268
#define	ISUMRMS			0x0269

#define	AWATT_ACC		0x02E5
#define	AWATTHR_LO		0x02E6
#define	AWATTHR_HI		0x02E7
#define	AVAR_ACC		0x02EF
#define	AVARHR_LO		0x02F0
#define	AVARHR_HI		0x02F1
#define	AVA_ACC			0x02F9
#define	AVAHR_LO		0x02FA
#define	AVAHR_HI		0x02FB
#define	AFWATT_ACC		0x0303
#define	AFWATTHR_LO		0x0304
#define	AFWATTHR_HI		0x0305
#define	AFVAR_ACC		0x030D
#define	AFVARHR_LO		0x030E
#define	AFVARHR_HI		0x030F
#define	AFVA_ACC		0x0317
#define	AFVAHR_LO		0x0318
#define	AFVAHR_HI		0x0319
#define	BWATT_ACC		0x0321
#define	BWATTHR_LO		0x0322
#define	BWATTHR_HI		0x0323
#define	BVAR_ACC		0x032B
#define	BVARHR_LO		0x032C
#define	BVARHR_HI		0x032D
#define	BVA_ACC			0x0335
#define	BVAHR_LO		0x0336
#define	BVAHR_HI		0x0337
#define	BFWATT_ACC		0x033F
#define	BFWATTHR_LO		0x0340
#define	BFWATTHR_HI		0x0341
#define	BFVAR_ACC		0x0349
#define	BFVARHR_LO		0x034A
#define	BFVARHR_HI		0x034B
#define	BFVA_ACC		0x0353
#define	BFVAHR_LO		0x0354
#define	BFVAHR_HI		0x0355
#define	CWATT_ACC		0x035D
#define	CWATTHR_LO		0x035E
#define	CWATTHR_HI		0x035F
#define	CVAR_ACC		0x0367
#define	CVARHR_LO		0x0368
#define	CVARHR_HI		0x0369
#define	CVA_ACC			0x0371
#define	CVAHR_LO		0x0372
#define	CVAHR_HI		0x0373
#define	CFWATT_ACC		0x037B
#define	CFWATTHR_LO		0x037C
#define	CFWATTHR_HI		0x037D
#define	CFVAR_ACC		0x0385
#define	CFVARHR_LO		0x0386
#define	CFVARHR_HI		0x0387
#define	CFVA_ACC		0x038F
#define	CFVAHR_LO		0x0390
#define	CFVAHR_HI		0x0391
#define	PWATT_ACC		0x0397
#define	NWATT_ACC		0x039B
#define	PVAR_ACC		0x039F
#define	NVAR_ACC		0x03A3

#define	APERIOD			0x0418
#define	BPERIOD			0x0419
#define	CPERIOD			0x041A
#define	COM_PERIOD		0x041B

#define	ANGL_VA_VB		0x0482
#define	ANGL_VB_VC		0x0483
#define	ANGL_VA_VC		0x0484
#define	ANGL_VA_IA		0x0485
#define	ANGL_VB_IB		0x0486
#define	ANGL_VC_IC		0x0487
#define	ANGL_IA_IB		0x0488
#define	ANGL_IB_IC		0x0489
#define	ANGL_IA_IC		0x048A

#define	TEMP_RSLT		0x04B7

#define	AI_SINC_DAT		0x0500
#define	AV_SINC_DAT		0x0501
#define	BI_SINC_DAT		0x0502
#define	BV_SINC_DAT		0x0503
#define	CI_SINC_DAT		0x0504
#define	CV_SINC_DAT		0x0505
#define	NI_SINC_DAT		0x0506
#define	AI_LPF_DAT		0x0510
#define	AV_LPF_DAT		0x0511
#define	BI_LPF_DAT		0x0512
#define	BV_LPF_DAT		0x0513
#define	CI_LPF_DAT		0x0514
#define	CV_LPF_DAT		0x0515
#define	NI_LPF_DAT		0x0516
#define	AV_PCF_1		0x0600
#define	BV_PCF_1		0x0601
#define	CV_PCF_1		0x0602
#define	NI_PCF_1		0x0603
#define	AI_PCF_1		0x0604
#define	BI_PCF_1		0x0605
#define	CI_PCF_1		0x0606
#define	AIRMS_1			0x0607
#define	BIRMS_1			0x0608
#define	CIRMS_1			0x0609
#define	AVRMS_1			0x060A
#define	BVRMS_1			0x060B
#define	CVRMS_1			0x060C
#define	NIRMS_1			0x060D
#define	AWATT_1			0x060E
#define	BWATT_1			0x060F
#define	CWATT_1			0x0610
#define	AVA_1			0x0611
#define	BVA_1			0x0612
#define	CVA_1			0x0613
#define	AVAR_1			0x0614
#define	BVAR_1			0x0615
#define	CVAR_1			0x0616
#define	AFVAR_1			0x0617
#define	BFVAR_1			0x0618
#define	CFVAR_1			0x0619
#define	APF_1			0x061A
#define	BPF_1			0x061B
#define	CPF_1			0x061C
#define	AVTHD_1			0x061D
#define	BVTHD_1			0x061E
#define	CVTHD_1			0x061F
#define	AITHD_1			0x0620
#define	BITHD_1			0x0621
#define	CITHD_1			0x0622
#define	AFWATT_1		0x0623
#define	BFWATT_1		0x0624
#define	CFWATT_1		0x0625
#define	AFVA_1			0x0626
#define	BFVA_1			0x0627
#define	CFVA_1			0x0628
#define	AFIRMS_1		0x0629
#define	BFIRMS_1		0x062A
#define	CFIRMS_1		0x062B
#define	AFVRMS_1		0x062C
#define	BFVRMS_1		0x062D
#define	CFVRMS_1		0x062E
#define	AIRMSONE_1		0x062F
#define	BIRMSONE_1		0x0630
#define	CIRMSONE_1		0x0631
#define	AVRMSONE_1		0x0632
#define	BVRMSONE_1		0x0633
#define	CVRMSONE_1		0x0634
#define	NIRMSONE_1		0x0635
#define	AIRMS1012_1		0x0636
#define	BIRMS1012_1		0x0637
#define	CIRMS1012_1		0x0638
#define	AVRMS1012_1		0x0639
#define	BVRMS1012_1		0x063A
#define	CVRMS1012_1		0x063B
#define	NIRMS1012_1		0x063C
#define	AV_PCF_2		0x0680
#define	AI_PCF_2		0x0681
#define	AIRMS_2			0x0682
#define	AVRMS_2			0x0683
#define	AWATT_2			0x0684
#define	AVA_2			0x0685
#define	AVAR_2			0x0686
#define	AFVAR_2			0x0687
#define	APF_2			0x0688
#define	AVTHD_2			0x0689
#define	AITHD_2			0x068A
#define	AFWATT_2		0x068B
#define	AFVA_2			0x068C
#define	AFIRMS_2		0x068D
#define	AFVRMS_2		0x068E
#define	AIRMSONE_2		0x068F
#define	AVRMSONE_2		0x0690
#define	AIRMS1012_2		0x0691
#define	AVRMS1012_2		0x0692
#define	BV_PCF_2		0x0693
#define	BI_PCF_2		0x0694
#define	BIRMS_2			0x0695
#define	BVRMS_2			0x0696
#define	BWATT_2			0x0697
#define	BVA_2			0x0698
#define	BVAR_2			0x0699
#define	BFVAR_2			0x069A
#define	BPF_2			0x069B
#define	BVTHD_2			0x069C
#define	BITHD_2			0x069D
#define	BFWATT_2		0x069E
#define	BFVA_2			0x069F
#define	BFIRMS_2		0x06A0
#define	BFVRMS_2		0x06A1
#define	BIRMSONE_2		0x06A2
#define	BVRMSONE_2		0x06A3
#define	BIRMS1012_2		0x06A4
#define	BVRMS1012_2		0x06A5
#define	CV_PCF_2		0x06A6
#define	CI_PCF_2		0x06A7
#define	CIRMS_2			0x06A8
#define	CVRMS_2			0x06A9
#define	CWATT_2			0x06AA
#define	CVA_2			0x06AB
#define	CVAR_2			0x06AC
#define	CFVAR_2			0x06AD
#define	CPF_2			0x06AE
#define	CVTHD_2			0x06AF
#define	CITHD_2			0x06B0
#define	CFWATT_2		0x06B1
#define	CFVA_2			0x06B2
#define	CFIRMS_2		0x06B3
#define	CFVRMS_2		0x06B4
#define	CIRMSONE_2		0x06B5
#define	CVRMSONE_2		0x06B6
#define	CIRMS1012_2		0x06B7
#define	CVRMS1012_2		0x06B8
#define	NI_PCF_2		0x06B9
#define	NIRMS_2			0x06BA
#define	NIRMSONE_2		0x06BB
#define	NIRMS1012_2		0x06BC

/**
 * @def Endereco dos Registros do ADE9000 - CALIBRACAO
 *
 * @brief Enderecos dos Registradores do ADE9000
 * @see Datasheet do ADE9000 - \git\...
 */
#define	AIGAIN			0x0000
#define	AIGAIN0			0x0001
#define	AIGAIN1			0x0002
#define	AIGAIN2			0x0003
#define	AIGAIN3			0x0004
#define	AIGAIN4			0x0005
#define	APHCAL0			0x0006
#define	APHCAL1			0x0007
#define	APHCAL2			0x0008
#define	APHCAL3			0x0009
#define	APHCAL4			0x000A
#define	AVGAIN			0x000B
#define	AIRMSOS			0x000C
#define	AVRMSOS			0x000D
#define	APGAIN			0x000E
#define	AWATTOS			0x000F
#define	AVAROS			0x0010
#define	AFWATTOS		0x0011
#define	AFVAROS			0x0012
#define	AIFRMSOS		0x0013
#define	AVFRMSOS		0x0014
#define	AVRMSONEOS		0x0015
#define	AIRMSONEOS		0x0016
#define	AVRMS1012OS		0x0017
#define	AIRMS1012OS		0x0018

#define	BIGAIN			0x0020
#define	BIGAIN0			0x0021
#define	BIGAIN1			0x0022
#define	BIGAIN2			0x0023
#define	BIGAIN3			0x0024
#define	BIGAIN4			0x0025
#define	BPHCAL0			0x0026
#define	BPHCAL1			0x0027
#define	BPHCAL2			0x0028
#define	BPHCAL3			0x0029
#define	BPHCAL4			0x002A
#define	BVGAIN			0x002B
#define	BIRMSOS			0x002C
#define	BVRMSOS			0x002D
#define	BPGAIN			0x002E
#define	BWATTOS			0x002F
#define	BVAROS			0x0030
#define	BFWATTOS		0x0031
#define	BFVAROS			0x0032
#define	BIFRMSOS		0x0033
#define	BVFRMSOS		0x0034
#define	BVRMSONEOS		0x0035
#define	BIRMSONEOS		0x0036
#define	BVRMS1012OS		0x0037
#define	BIRMS1012OS		0x0038

#define	CIGAIN			0x0040
#define	CIGAIN0			0x0041
#define	CIGAIN1			0x0042
#define	CIGAIN2			0x0043
#define	CIGAIN3			0x0044
#define	CIGAIN4			0x0045
#define	CPHCAL0			0x0046
#define	CPHCAL1			0x0047
#define	CPHCAL2			0x0048
#define	CPHCAL3			0x0049
#define	CPHCAL4			0x004A
#define	CVGAIN			0x004B
#define	CIRMSOS			0x004C
#define	CVRMSOS			0x004D
#define	CPGAIN			0x004E
#define	CWATTOS			0x004F
#define	CVAROS			0x0050
#define	CFWATTOS		0x0051
#define	CFVAROS			0x0052
#define	CIFRMSOS		0x0053
#define	CVFRMSOS		0x0054
#define	CVRMSONEOS		0x0055
#define	CIRMSONEOS		0x0056
#define	CVRMS1012OS		0x0057
#define	CIRMS1012OS		0x0058

#define	NIRMSOS			0x006B
#define	ISUMRMSOS		0x006C
#define	NIGAIN			0x006D
#define	NPHCAL			0x006E
#define	NIRMSONEOS		0x006F
#define	NIRMS1012OS		0x0070
#define	VNOM			0x0071

#define	TEMP_TRIM		0x0474

/**
 * @def Endereco dos Registros do ADE9000 - DEFINICOES DE FUNCIONALIDADE
 *
 * @brief Enderecos dos Registradores do ADE9000
 * @see Datasheet do ADE9000 - \git\...
 */
#define	CONFIG0			0x0060
#define	MTTHR_L0		0x0061
#define	MTTHR_L1		0x0062
#define	MTTHR_L2		0x0063
#define	MTTHR_L3		0x0064
#define	MTTHR_L4		0x0065
#define	MTTHR_H0		0x0066
#define	MTTHR_H1		0x0067
#define	MTTHR_H2		0x0068
#define	MTTHR_H3		0x0069
#define	MTTHR_H4		0x006A

#define	DICOEFF			0x0072
#define	ISUMLVL			0x0073

#define	MASK0			0x0405
#define	MASK1			0x0406
#define	EVENT_MASK		0x0407
#define	OILVL			0x0409

#define	USER_PERIOD		0x040E
#define	VLEVEL			0x040F
#define	DIP_LVL			0x0410

#define	SWELL_LVL		0x0414

#define	ACT_NL_LVL		0x041C
#define	REACT_NL_LVL	0x041D
#define	APP_NL_LVL		0x041E

#define	WTHR			0x0420
#define	VARTHR			0x0421
#define	VATHR			0x0422

#define	ADC_REDIRECT	0x0424
#define	CF_LCFG			0x0425

#define	RUN				0x0480
#define	CONFIG1			0x0481

#define	DIP_CYC			0x048B
#define	SWELL_CYC		0x048C

#define	CFMODE			0x0490
#define	COMPMODE		0x0491
#define	ACCMODE			0x0492
#define	CONFIG3			0x0493
#define	CF1DEN			0x0494
#define	CF2DEN			0x0495
#define	CF3DEN			0x0496
#define	CF4DEN			0x0497
#define	ZXTOUT			0x0498
#define	ZXTHRSH			0x0499
#define	ZX_LP_SEL		0x049A
#define	SEQ_CYC			0x049C

#define	WFB_CFG			0x04A0
#define	WFB_PG_IRQEN	0x04A1
#define	WFB_TRG_CFG		0x04A2

#define	CONFIG2			0x04AF
#define	EP_CFG			0x04B0
#define	PWR_TIME		0x04B1
#define	EGY_TIME		0x04B2
#define	CRC_FORCE		0x04B4
#define	CRC_OPTEN		0x04B5
#define	TEMP_CFG		0x04B6
#define	TEMP_RSLT		0x04B7
#define	PGA_GAIN		0x04B9
#define	CHNL_DIS		0x04BA
#define	WR_LOCK			0x04BF
#define	VAR_DIS			0x04E0

/**
 * @def Endereco dos Registros do ADE9000 - MONITORAMENTO DE STATUS
 *
 * @brief Enderecos dos Registradores do ADE9000
 * @see Datasheet do ADE9000 - \git\...
 */
#define	AMTREGION		0x021D

#define	BMTREGION		0x023D

#define	CMTREGION		0x025D

#define	STATUS0			0x0402
#define	STATUS1			0x0403
#define	EVENT_STATUS	0x0404

#define	PHNOLOAD		0x041F

#define	LAST_DATA_32	0x0423

#define	OISTATUS		0x048F

#define	PHSIGN			0x049D

#define	WFB_TRG_STAT	0x04A3

#define	CRC_RSLT		0x04A8
#define	CRC_SPI			0x04A9
#define	LAST_DATA_16	0x04AC
#define	LAST_CMD		0x04AE

/**
 * @def Endereco dos Registros do ADE9000 - EVENTOS
 *
 * @brief Enderecos dos Registradores do ADE9000
 * @see Datasheet do ADE9000 - \git\...
 */
#define	IPEAK			0x0400
#define	VPEAK			0x0401

#define	OIA				0x040A
#define	OIB				0x040B
#define	OIC				0x040C
#define	OIN				0x040D

#define	DIPA			0x0411
#define	DIPB			0x0412
#define	DIPC			0x0413

#define	SWELLA			0x0415
#define	SWELLB			0x0416
#define	SWELLC			0x0417

/**
 * @def Endereco dos Registros do ADE9000 - EVENTOS
 *
 * @brief Enderecos dos Registradores do ADE9000
 * @see Datasheet do ADE9000 - \git\...
 */

#define	TAM_ADDRESS		2

/**
 * @def Endereco dos Registros do ADE9000 - TAMANHO DOS DADOS
 *
 * @brief Enderecos dos Registradores do ADE9000
 * @see Datasheet do ADE9000 - \git\...
 */

#define	TAM_AIGAIN			2
#define	TAM_AIGAIN0			2
#define	TAM_AIGAIN1			2
#define	TAM_AIGAIN2			2
#define	TAM_AIGAIN3			2
#define	TAM_AIGAIN4			2
#define	TAM_APHCAL0			2
#define	TAM_APHCAL1			2
#define	TAM_APHCAL2			2
#define	TAM_APHCAL3			2
#define	TAM_APHCAL4			2
#define	TAM_AVGAIN			2
#define	TAM_AIRMSOS			2
#define	TAM_AVRMSOS			2
#define	TAM_APGAIN			2
#define	TAM_AWATTOS			2
#define	TAM_AVAROS			2
#define	TAM_AFWATTOS		2
#define	TAM_AFVAROS			2
#define	TAM_AIFRMSOS		2
#define	TAM_AVFRMSOS		2
#define	TAM_AVRMSONEOS		2
#define	TAM_AIRMSONEOS		2
#define	TAM_AVRMS1012OS		2
#define	TAM_AIRMS1012OS		2
#define	TAM_BIGAIN			2
#define	TAM_BIGAIN0			2
#define	TAM_BIGAIN1			2
#define	TAM_BIGAIN2			2
#define	TAM_BIGAIN3			2
#define	TAM_BIGAIN4			2
#define	TAM_BPHCAL0			2
#define	TAM_BPHCAL1			2
#define	TAM_BPHCAL2			2
#define	TAM_BPHCAL3			2
#define	TAM_BPHCAL4			2
#define	TAM_BVGAIN			2
#define	TAM_BIRMSOS			2
#define	TAM_BVRMSOS			2
#define	TAM_BPGAIN			2
#define	TAM_BWATTOS			2
#define	TAM_BVAROS			2
#define	TAM_BFWATTOS		2
#define	TAM_BFVAROS			2
#define	TAM_BIFRMSOS		2
#define	TAM_BVFRMSOS		2
#define	TAM_BVRMSONEOS		2
#define	TAM_BIRMSONEOS		2
#define	TAM_BVRMS1012OS		2
#define	TAM_BIRMS1012OS		2
#define	TAM_CIGAIN			2
#define	TAM_CIGAIN0			2
#define	TAM_CIGAIN1			2
#define	TAM_CIGAIN2			2
#define	TAM_CIGAIN3			2
#define	TAM_CIGAIN4			2
#define	TAM_CPHCAL0			2
#define	TAM_CPHCAL1			2
#define	TAM_CPHCAL2			2
#define	TAM_CPHCAL3			2
#define	TAM_CPHCAL4			2
#define	TAM_CVGAIN			2
#define	TAM_CIRMSOS			2
#define	TAM_CVRMSOS			2
#define	TAM_CPGAIN			2
#define	TAM_CWATTOS			2
#define	TAM_CVAROS			2
#define	TAM_CFWATTOS		2
#define	TAM_CFVAROS			2
#define	TAM_CIFRMSOS		2
#define	TAM_CVFRMSOS		2
#define	TAM_CVRMSONEOS		2
#define	TAM_CIRMSONEOS		2
#define	TAM_CVRMS1012OS		2
#define	TAM_CIRMS1012OS		2
#define	TAM_CONFIG0			2
#define	TAM_MTTHR_L0		2
#define	TAM_MTTHR_L1		2
#define	TAM_MTTHR_L2		2
#define	TAM_MTTHR_L3		2
#define	TAM_MTTHR_L4		2
#define	TAM_MTTHR_H0		2
#define	TAM_MTTHR_H1		2
#define	TAM_MTTHR_H2		2
#define	TAM_MTTHR_H3		2
#define	TAM_MTTHR_H4		2
#define	TAM_NIRMSOS			2
#define	TAM_ISUMRMSOS		2
#define	TAM_NIGAIN			2
#define	TAM_NPHCAL			2
#define	TAM_NIRMSONEOS		2
#define	TAM_NIRMS1012OS		2
#define	TAM_VNOM			2
#define	TAM_DICOEFF			2
#define	TAM_ISUMLVL			2
#define	TAM_AI_PCF			2
#define	TAM_AV_PCF			2
#define	TAM_AIRMS			2
#define	TAM_AVRMS			2
#define	TAM_AIFRMS			2
#define	TAM_AVFRMS			2
#define	TAM_AWATT			2
#define	TAM_AVAR			2
#define	TAM_AVA				2
#define	TAM_AFWATT			2
#define	TAM_AFVAR			2
#define	TAM_AFVA			2
#define	TAM_APF				2
#define	TAM_AVTHD			2
#define	TAM_AITHD			2
#define	TAM_AIRMSONE		2
#define	TAM_AVRMSONE		2
#define	TAM_AIRMS1012		2
#define	TAM_AVRMS1012		2
#define	TAM_AMTREGION		2
#define	TAM_BI_PCF			2
#define	TAM_BV_PCF			2
#define	TAM_BIRMS			2
#define	TAM_BVRMS			2
#define	TAM_BIFRMS			2
#define	TAM_BVFRMS			2
#define	TAM_BWATT			2
#define	TAM_BVAR			2
#define	TAM_BVA				2
#define	TAM_BFWATT			2
#define	TAM_BFVAR			2
#define	TAM_BFVA			2
#define	TAM_BPF				2
#define	TAM_BVTHD			2
#define	TAM_BITHD			2
#define	TAM_BIRMSONE		2
#define	TAM_BVRMSONE		2
#define	TAM_BIRMS1012		2
#define	TAM_BVRMS1012		2
#define	TAM_BMTREGION		2
#define	TAM_CI_PCF			2
#define	TAM_CV_PCF			2
#define	TAM_CIRMS			2
#define	TAM_CVRMS			2
#define	TAM_CIFRMS			2
#define	TAM_CVFRMS			2
#define	TAM_CWATT			2
#define	TAM_CVAR			2
#define	TAM_CVA				2
#define	TAM_CFWATT			2
#define	TAM_CFVAR			2
#define	TAM_CFVA			2
#define	TAM_CPF				2
#define	TAM_CVTHD			2
#define	TAM_CITHD			2
#define	TAM_CIRMSONE		2
#define	TAM_CVRMSONE		2
#define	TAM_CIRMS1012		2
#define	TAM_CVRMS1012		2
#define	TAM_CMTREGION		2
#define	TAM_NI_PCF			2
#define	TAM_NIRMS			2
#define	TAM_NIRMSONE		2
#define	TAM_NIRMS1012		2
#define	TAM_ISUMRMS			2
#define	TAM_VERSION2		2
#define	TAM_AWATT_ACC		2
#define	TAM_AWATTHR_LO		2
#define	TAM_AWATTHR_HI		2
#define	TAM_AVAR_ACC		2
#define	TAM_AVARHR_LO		2
#define	TAM_AVARHR_HI		2
#define	TAM_AVA_ACC			2
#define	TAM_AVAHR_LO		2
#define	TAM_AVAHR_HI		2
#define	TAM_AFWATT_ACC		2
#define	TAM_AFWATTHR_LO		2
#define	TAM_AFWATTHR_HI		2
#define	TAM_AFVAR_ACC		2
#define	TAM_AFVARHR_LO		2
#define	TAM_AFVARHR_HI		2
#define	TAM_AFVA_ACC		2
#define	TAM_AFVAHR_LO		2
#define	TAM_AFVAHR_HI		2
#define	TAM_BWATT_ACC		2
#define	TAM_BWATTHR_LO		2
#define	TAM_BWATTHR_HI		2
#define	TAM_BVAR_ACC		2
#define	TAM_BVARHR_LO		2
#define	TAM_BVARHR_HI		2
#define	TAM_BVA_ACC			2
#define	TAM_BVAHR_LO		2
#define	TAM_BVAHR_HI		2
#define	TAM_BFWATT_ACC		2
#define	TAM_BFWATTHR_LO		2
#define	TAM_BFWATTHR_HI		2
#define	TAM_BFVAR_ACC		2
#define	TAM_BFVARHR_LO		2
#define	TAM_BFVARHR_HI		2
#define	TAM_BFVA_ACC		2
#define	TAM_BFVAHR_LO		2
#define	TAM_BFVAHR_HI		2
#define	TAM_CWATT_ACC		2
#define	TAM_CWATTHR_LO		2
#define	TAM_CWATTHR_HI		2
#define	TAM_CVAR_ACC		2
#define	TAM_CVARHR_LO		2
#define	TAM_CVARHR_HI		2
#define	TAM_CVA_ACC			2
#define	TAM_CVAHR_LO		2
#define	TAM_CVAHR_HI		2
#define	TAM_CFWATT_ACC		2
#define	TAM_CFWATTHR_LO		2
#define	TAM_CFWATTHR_HI		2
#define	TAM_CFVAR_ACC		2
#define	TAM_CFVARHR_LO		2
#define	TAM_CFVARHR_HI		2
#define	TAM_CFVA_ACC		2
#define	TAM_CFVAHR_LO		2
#define	TAM_CFVAHR_HI		2
#define	TAM_PWATT_ACC		2
#define	TAM_NWATT_ACC		2
#define	TAM_PVAR_ACC		2
#define	TAM_NVAR_ACC		2
#define	TAM_IPEAK			2
#define	TAM_VPEAK			2
#define	TAM_STATUS0			2
#define	TAM_STATUS1			2
#define	TAM_EVENT_STATUS	2
#define	TAM_MASK0			2
#define	TAM_MASK1			2
#define	TAM_EVENT_MASK		2
#define	TAM_OILVL			2
#define	TAM_OIA				2
#define	TAM_OIB				2
#define	TAM_OIC				2
#define	TAM_OIN				2
#define	TAM_USER_PERIOD		2
#define	TAM_VLEVEL			2
#define	TAM_DIP_LVL			2
#define	TAM_DIPA			2
#define	TAM_DIPB			2
#define	TAM_DIPC			2
#define	TAM_SWELL_LVL		2
#define	TAM_SWELLA			2
#define	TAM_SWELLB			2
#define	TAM_SWELLC			2
#define	TAM_APERIOD			2
#define	TAM_BPERIOD			2
#define	TAM_CPERIOD			2
#define	TAM_COM_PERIOD		2
#define	TAM_ACT_NL_LVL		2
#define	TAM_REACT_NL_LVL	2
#define	TAM_APP_NL_LVL		2
#define	TAM_PHNOLOAD		2
#define	TAM_WTHR			2
#define	TAM_VARTHR			2
#define	TAM_VATHR			2
#define	TAM_LAST_DATA_32	2
#define	TAM_ADC_REDIRECT	2
#define	TAM_CF_LCFG			2
#define	TAM_PART_ID			2
#define	TAM_TEMP_TRIM		2
#define	TAM_RUN				1
#define	TAM_CONFIG1			1
#define	TAM_ANGL_VA_VB		1
#define	TAM_ANGL_VB_VC		1
#define	TAM_ANGL_VA_VC		1
#define	TAM_ANGL_VA_IA		1
#define	TAM_ANGL_VB_IB		1
#define	TAM_ANGL_VC_IC		1
#define	TAM_ANGL_IA_IB		1
#define	TAM_ANGL_IB_IC		1
#define	TAM_ANGL_IA_IC		1
#define	TAM_DIP_CYC			1
#define	TAM_SWELL_CYC		1
#define	TAM_OISTATUS		1
#define	TAM_CFMODE			1
#define	TAM_COMPMODE		1
#define	TAM_ACCMODE			1
#define	TAM_CONFIG3			1
#define	TAM_CF1DEN			1
#define	TAM_CF2DEN			1
#define	TAM_CF3DEN			1
#define	TAM_CF4DEN			1
#define	TAM_ZXTOUT			1
#define	TAM_ZXTHRSH			1
#define	TAM_ZX_LP_SEL		1
#define	TAM_SEQ_CYC			1
#define	TAM_PHSIGN			1
#define	TAM_WFB_CFG			1
#define	TAM_WFB_PG_IRQEN	1
#define	TAM_WFB_TRG_CFG		1
#define	TAM_WFB_TRG_STAT	1
#define	TAM_CONFIG5			1
#define	TAM_CRC_RSLT		1
#define	TAM_CRC_SPI			1
#define	TAM_LAST_DATA_16	1
#define	TAM_LAST_CMD		1
#define	TAM_CONFIG2			1
#define	TAM_EP_CFG			1
#define	TAM_PWR_TIME		1
#define	TAM_EGY_TIME		1
#define	TAM_CRC_FORCE		1
#define	TAM_CRC_OPTEN		1
#define	TAM_TEMP_CFG		1
#define	TAM_TEMP_RSLT		1
#define	TAM_PGA_GAIN		1
#define	TAM_CHNL_DIS		1
#define	TAM_WR_LOCK			1
#define	TAM_VAR_DIS			1
#define	TAM_RESERVED1		1
#define	TAM_Version			1
#define	TAM_AI_SINC_DAT		2
#define	TAM_AV_SINC_DAT		2
#define	TAM_BI_SINC_DAT		2
#define	TAM_BV_SINC_DAT		2
#define	TAM_CI_SINC_DAT		2
#define	TAM_CV_SINC_DAT		2
#define	TAM_NI_SINC_DAT		2
#define	TAM_AI_LPF_DAT		2
#define	TAM_AV_LPF_DAT		2
#define	TAM_BI_LPF_DAT		2
#define	TAM_BV_LPF_DAT		2
#define	TAM_CI_LPF_DAT		2
#define	TAM_CV_LPF_DAT		2
#define	TAM_NI_LPF_DAT		2
#define	TAM_AV_PCF_1		2
#define	TAM_BV_PCF_1		2
#define	TAM_CV_PCF_1		2
#define	TAM_NI_PCF_1		2
#define	TAM_AI_PCF_1		2
#define	TAM_BI_PCF_1		2
#define	TAM_CI_PCF_1		2
#define	TAM_AIRMS_1			2
#define	TAM_BIRMS_1			2
#define	TAM_CIRMS_1			2
#define	TAM_AVRMS_1			2
#define	TAM_BVRMS_1			2
#define	TAM_CVRMS_1			2
#define	TAM_NIRMS_1			2
#define	TAM_AWATT_1			2
#define	TAM_BWATT_1			2
#define	TAM_CWATT_1			2
#define	TAM_AVA_1			2
#define	TAM_BVA_1			2
#define	TAM_CVA_1			2
#define	TAM_AVAR_1			2
#define	TAM_BVAR_1			2
#define	TAM_CVAR_1			2
#define	TAM_AFVAR_1			2
#define	TAM_BFVAR_1			2
#define	TAM_CFVAR_1			2
#define	TAM_APF_1			2
#define	TAM_BPF_1			2
#define	TAM_CPF_1			2
#define	TAM_AVTHD_1			2
#define	TAM_BVTHD_1			2
#define	TAM_CVTHD_1			2
#define	TAM_AITHD_1			2
#define	TAM_BITHD_1			2
#define	TAM_CITHD_1			2
#define	TAM_AFWATT_1		2
#define	TAM_BFWATT_1		2
#define	TAM_CFWATT_1		2
#define	TAM_AFVA_1			2
#define	TAM_BFVA_1			2
#define	TAM_CFVA_1			2
#define	TAM_AFIRMS_1		2
#define	TAM_BFIRMS_1		2
#define	TAM_CFIRMS_1		2
#define	TAM_AFVRMS_1		2
#define	TAM_BFVRMS_1		2
#define	TAM_CFVRMS_1		2
#define	TAM_AIRMSONE_1		2
#define	TAM_BIRMSONE_1		2
#define	TAM_CIRMSONE_1		2
#define	TAM_AVRMSONE_1		2
#define	TAM_BVRMSONE_1		2
#define	TAM_CVRMSONE_1		2
#define	TAM_NIRMSONE_1		2
#define	TAM_AIRMS1012_1		2
#define	TAM_BIRMS1012_1		2
#define	TAM_CIRMS1012_1		2
#define	TAM_AVRMS1012_1		2
#define	TAM_BVRMS1012_1		2
#define	TAM_CVRMS1012_1		2
#define	TAM_NIRMS1012_1		2
#define	TAM_AV_PCF_2		2
#define	TAM_AI_PCF_2		2
#define	TAM_AIRMS_2			2
#define	TAM_AVRMS_2			2
#define	TAM_AWATT_2			2
#define	TAM_AVA_2			2
#define	TAM_AVAR_2			2
#define	TAM_AFVAR_2			2
#define	TAM_APF_2			2
#define	TAM_AVTHD_2			2
#define	TAM_AITHD_2			2
#define	TAM_AFWATT_2		2
#define	TAM_AFVA_2			2
#define	TAM_AFIRMS_2		2
#define	TAM_AFVRMS_2		2
#define	TAM_AIRMSONE_2		2
#define	TAM_AVRMSONE_2		2
#define	TAM_AIRMS1012_2		2
#define	TAM_AVRMS1012_2		2
#define	TAM_BV_PCF_2		2
#define	TAM_BI_PCF_2		2
#define	TAM_BIRMS_2			2
#define	TAM_BVRMS_2			2
#define	TAM_BWATT_2			2
#define	TAM_BVA_2			2
#define	TAM_BVAR_2			2
#define	TAM_BFVAR_2			2
#define	TAM_BPF_2			2
#define	TAM_BVTHD_2			2
#define	TAM_BITHD_2			2
#define	TAM_BFWATT_2		2
#define	TAM_BFVA_2			2
#define	TAM_BFIRMS_2		2
#define	TAM_BFVRMS_2		2
#define	TAM_BIRMSONE_2		2
#define	TAM_BVRMSONE_2		2
#define	TAM_BIRMS1012_2		2
#define	TAM_BVRMS1012_2		2
#define	TAM_CV_PCF_2		2
#define	TAM_CI_PCF_2		2
#define	TAM_CIRMS_2			2
#define	TAM_CVRMS_2			2
#define	TAM_CWATT_2			2
#define	TAM_CVA_2			2
#define	TAM_CVAR_2			2
#define	TAM_CFVAR_2			2
#define	TAM_CPF_2			2
#define	TAM_CVTHD_2			2
#define	TAM_CITHD_2			2
#define	TAM_CFWATT_2		2
#define	TAM_CFVA_2			2
#define	TAM_CFIRMS_2		2
#define	TAM_CFVRMS_2		2
#define	TAM_CIRMSONE_2		2
#define	TAM_CVRMSONE_2		2
#define	TAM_CIRMS1012_2		2
#define	TAM_CVRMS1012_2		2
#define	TAM_NI_PCF_2		2
#define	TAM_NIRMS_2			2
#define	TAM_NIRMSONE_2		2
#define	TAM_NIRMS1012_2		2

/**
 * @def Endereco dos Registros do ADE9000 - VALORES DOS REGISTROS
 *
 * @brief Enderecos dos Registradores do ADE9000
 * @see Datasheet do ADE9000 - \git\...
 */
uint16_t DEFAULT_USER_PERIOD[] = {0x0085, 0x5554};
uint16_t DEFAULT_VLEVEL[] = {0x0005, 0xAAA1};
uint16_t DEFAULT_DIP_LVL[] = {0x000F, 0xFFFF};
uint16_t DEFAULT_SWELL_LVL[] = {0x00FF, 0xFFFF};
uint16_t DEFAULT_RUN[] = {0x0001};
uint16_t DEFAULT_CONFIG1[] = {0x0800};
uint16_t DEFAULT_CFMODE[] = {0xF000};
uint16_t DEFAULT_ACCMODE[] = {0x0100};
uint16_t DEFAULT_CONFIG3[] = {0x0000};
uint16_t DEFAULT_WFB_CFG[] = {0x12F0};
uint16_t DEFAULT_EP_CFG[] = {0x0022};
uint16_t DEFAULT_WFB_PG_IRQEN[] = {0x8080};
uint16_t DEFAULT_MASK0[] = {0x0002, 0x0000};

/**
 * @def Fases
 *
 * @brief Definicoes das constantes Fases A, B e C do Sistema
 *
 */
#define FASEA		    0x00
#define FASEB		    0x01
#define FASEC		    0x02
#define	FASE_NONE		0x03

/**
 * @def Full scale Codes
 *
 * @brief Full scale Codes referred from Datasheet.Respective digital codes are produced when ADC inputs are at full scale. Donot Change.
 * @see Datasheet do ADE9000 (CALIBRATION)
 *
 */
#define ADE9000_RMS_FULL_SCALE_CODES  52702092
#define ADE9000_WATT_FULL_SCALE_CODES 20694066
#define ADE9000_RESAMPLED_FULL_SCALE_CODES  18196
#define ADE9000_PCF_FULL_SCALE_CODES  74532013

/**
 * @def Waveform buffer Settings
 *
 * @brief Waveform buffer Settings. Donot Change.
 * @see Datasheet do ADE9000 (BURST READ)
 *
 */
#define ADE9000_WFB_CFG 0x1000			//Neutral current samples enabled, Resampled data enabled
										//Burst all channels
#define WFB_ELEMENT_ARRAY_SIZE 512  	//size of buffer to read. 512 Max.Each element IA,VA...IN has max 512 points
										//[Size of waveform buffer/number of sample sets = 2048/4 = 512]
										//(Refer ADE9000 technical reference manual for more details)

#define ESPECTRO_ARRAY_SIZE (WFB_ELEMENT_ARRAY_SIZE/2)

#endif /* INC_ADE9000_H_ */
