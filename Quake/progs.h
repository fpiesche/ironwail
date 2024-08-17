/*
Copyright (C) 1996-2001 Id Software, Inc.
Copyright (C) 2002-2009 John Fitzgibbons and others
Copyright (C) 2010-2014 QuakeSpasm developers

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#ifndef QUAKE_PROGS_H
#define QUAKE_PROGS_H

#include "pr_comp.h"	/* defs shared with qcc */
#include "progdefs.h"	/* generated by program cdefs */

typedef enum showbboxflags_t
{
	SHOWBBOX_LINK_NONE		= 0,
	SHOWBBOX_LINK_OUTGOING	= 1,
	SHOWBBOX_LINK_INCOMING	= 2,
	SHOWBBOX_LINK_BOTH		= SHOWBBOX_LINK_OUTGOING | SHOWBBOX_LINK_INCOMING,
} showbboxflags_t;

typedef union eval_s
{
	string_t	string;
	float		_float;
	float		vector[3];
	func_t		function;
	int		_int;
	int		edict;
} eval_t;

#define	MAX_ENT_LEAFS	32
typedef struct edict_s
{
	qboolean	free;			/* don't modify directly, use ED_AddToFreeList/ED_RemoveFromFreeList */
	link_t		freechain;
	link_t		area;			/* linked to a division node or leaf */

	int		num_leafs;
	int		leafnums[MAX_ENT_LEAFS];

	entity_state_t	baseline;
	unsigned char	alpha;			/* johnfitz -- hack to support alpha since it's not part of entvars_t */
	unsigned char	scale;			/* Quakespasm: added for model scale support. */
	qboolean	forcewater;			/* mod overrides waterlevel */
	qboolean	sendforcewater;		/* waterlevel override has changed and needs to be sent over to the client */
	qboolean	sendinterval;		/* johnfitz -- send time until nextthink to client for better lerp timing */
	float		oldframe;
	float		oldthinktime;

	int					showbboxframe;		/* last render frame this entity was highlighted by r_showbboxes & co */
	showbboxflags_t		showbboxflags;		/* highlighted entity link types */

	float		freetime;		/* sv.time when the object was freed */
	entvars_t	v;			/* C exported fields from progs */

	/* other fields from progs come immediately after */
} edict_t;

#define	EDICT_FROM_AREA(l)	STRUCT_FROM_LINK(l,edict_t,area)

//============================================================================

#define MAX_BUILTINS		1280
typedef void (*builtin_t) (void);

typedef struct
{
	int		s;
	dfunction_t	*f;
} prstack_t;

typedef struct prhashtable_s
{
	int			capacity;
	const char	**strings;
	int			*indices;
} prhashtable_t;

struct pr_extfuncs_s
{
/*ssqc*/
#define QCEXTFUNCS_SV \
	QCEXTFUNC(SV_ParseClientCommand,	"void(string cmd)")		\
/*csqc*/
#define QCEXTFUNCS_CS \
	QCEXTFUNC(CSQC_Init,				"void(float apilevel, string enginename, float engineversion)")	\
	QCEXTFUNC(CSQC_Shutdown,			"void()")	\
	QCEXTFUNC(CSQC_DrawHud,				"void(vector virtsize, float showscores)")							/*simple: for the simple(+limited) hud-only csqc interface.*/	\
	QCEXTFUNC(CSQC_DrawScores,			"void(vector virtsize, float showscores)")							/*simple: (optional) for the simple hud-only csqc interface.*/		\

#define QCEXTFUNC(n,t) func_t n;
	QCEXTFUNCS_SV
	QCEXTFUNCS_CS
#undef QCEXTFUNC
};
extern	cvar_t	pr_checkextension;	//if 0, extensions are disabled (unless they'd be fatal, but they're still spammy)
	
struct pr_extglobals_s
{
#define QCEXTGLOBALS_CSQC \
	QCEXTGLOBAL_FLOAT(cltime)\
	QCEXTGLOBAL_FLOAT(clframetime)\
	QCEXTGLOBAL_FLOAT(maxclients)\
	QCEXTGLOBAL_FLOAT(intermission)\
	QCEXTGLOBAL_FLOAT(intermission_time)\
	QCEXTGLOBAL_FLOAT(player_localnum)\
	QCEXTGLOBAL_FLOAT(player_localentnum)\
	QCEXTGLOBAL_VECTOR(view_angles)\
	QCEXTGLOBAL_FLOAT(clientcommandframe)\
	QCEXTGLOBAL_FLOAT(servercommandframe)\
	//end
#define QCEXTGLOBAL_FLOAT(n) float *n;
#define QCEXTGLOBAL_INT(n) int *n;
#define QCEXTGLOBAL_VECTOR(n) float *n;
	QCEXTGLOBALS_CSQC
#undef QCEXTGLOBAL_FLOAT
#undef QCEXTGLOBAL_INT
#undef QCEXTGLOBAL_VECTOR
};

struct pr_extfields_s
{	//various fields that might be wanted by the engine. -1 == invalid

#define QCEXTFIELDS_ALL	\
	/*renderscene means we need a number of fields here*/	\
	QCEXTFIELD(alpha,					".float")				/*float*/	\
	QCEXTFIELD(scale,					".float")				/*float*/	\
	QCEXTFIELD(colormod,				".vector")			/*vector*/	\
	/*end of list*/
#define QCEXTFIELDS_GAME	\
	/*stuff used by csqc+ssqc, but not menu*/	\
	QCEXTFIELD(customphysics,			".void()")/*function*/	\
	QCEXTFIELD(gravity,					".float")			/*float*/	\
	//end of list
#define QCEXTFIELDS_SS	\
	/*ssqc-only*/	\
	QCEXTFIELD(items2,					"//.float")				/*float*/	\
	QCEXTFIELD(movement,				".vector")			/*vector*/	\
	QCEXTFIELD(viewmodelforclient,		".entity")	/*entity*/	\
	QCEXTFIELD(exteriormodeltoclient,	".entity")	/*entity*/	\
	QCEXTFIELD(traileffectnum,			".float")		/*float*/	\
	QCEXTFIELD(emiteffectnum,			".float")		/*float*/	\
	QCEXTFIELD(button3,					".float")			/*float*/	\
	QCEXTFIELD(button4,					".float")			/*float*/	\
	QCEXTFIELD(button5,					".float")			/*float*/	\
	QCEXTFIELD(button6,					".float")			/*float*/	\
	QCEXTFIELD(button7,					".float")			/*float*/	\
	QCEXTFIELD(button8,					".float")			/*float*/	\
	QCEXTFIELD(viewzoom,				".float")			/*float*/	\
	QCEXTFIELD(SendEntity,				".float(entity to, float changedflags)")			/*function*/	\
	QCEXTFIELD(SendFlags,				".float")			/*float. :( */	\
	//end of list

#define QCEXTFIELD(n,t) int n;
	QCEXTFIELDS_ALL
	QCEXTFIELDS_GAME
	QCEXTFIELDS_SS
#undef QCEXTFIELD
};

#define QCEXTENSIONS_ALL						\
	QCEXTENSION(FRIK_FILE)						\
	QCEXTENSION(FTE_STRINGS)					\
	QCEXTENSION(FTE_QC_CHECKCOMMAND)			\
	QCEXTENSION(DP_QC_ETOS)						\
	QCEXTENSION(DP_QC_STRING_CASE_FUNCTIONS)	\
	QCEXTENSION(DP_QC_SPRINTF)					\
	QCEXTENSION(DP_QC_TOKENIZE_CONSOLE)			\
	QCEXTENSION(DP_QC_STRFTIME)					\
	QCEXTENSION(KRIMZON_SV_PARSECLIENTCOMMAND)	\

/*
QCEXTENSION(DP_QC_MINMAXBOUND)				\
QCEXTENSION(DP_QC_SINCOSSQRTPOW)			\
QCEXTENSION(DP_QC_ASINACOSATANATAN2TAN)		\
QCEXTENSION(DP_QC_VECTORVECTORS)			\
*/
typedef enum
{
	STD_QC,

	#define QCEXTENSION(name)		name,
	QCEXTENSIONS_ALL
	#undef QCEXTENSION

	QCEXT_COUNT,
} qcextension_t;

typedef struct qcvm_s
{
	dprograms_t		*progs;
	dfunction_t		*functions;
	dstatement_t	*statements;
	float			*globals;	/* same as pr_global_struct */
	ddef_t			*fielddefs;	//yay reflection.

	int				edict_size;	/* in bytes */

	int				effects_mask; // only enable 2021 rerelease quad/penta dlights when applicable

	builtin_t		builtins[MAX_BUILTINS];
	int				numbuiltins;

	int				argc;

	qboolean		trace;
	dfunction_t		*xfunction;
	int				xstatement;

	unsigned short	crc;

	struct pr_extfuncs_s extfuncs;
	struct pr_extglobals_s extglobals;
	struct pr_extfields_s extfields;

	qcextension_t	builtin_ext[MAX_BUILTINS];
	uint32_t		warned_builtin[2][(MAX_BUILTINS + 31) / 32];
	uint32_t		checked_ext[(QCEXT_COUNT + 31) / 32];
	uint32_t		advertised_ext[(QCEXT_COUNT + 31) / 32];

	//was static inside pr_edict
	char			*strings;
	int				stringssize;
	const char		**knownstrings;
	int				maxknownstrings;
	int				numknownstrings;
	const char		**firstfreeknownstring; // free list (singly linked)

	unsigned char	*knownzone;
	size_t			knownzonesize;

	ddef_t			*globaldefs;

	prhashtable_t	ht_fields;
	prhashtable_t	ht_functions;
	prhashtable_t	ht_globals;

	//originally defined in pr_exec, but moved into the switchable qcvm struct
#define	MAX_STACK_DEPTH		1024 /*was 64*/	/* was 32 */
	prstack_t		stack[MAX_STACK_DEPTH];
	int				depth;

#define	LOCALSTACK_SIZE		16384 /* was 2048*/
	int				localstack[LOCALSTACK_SIZE];
	int				localstack_used;

	//originally part of the sv_state_t struct
	//FIXME: put worldmodel in here too.
	double		time;
	int			num_edicts;
	int			reserved_edicts;
	int			max_edicts;
	link_t		free_edicts;		// linked list of free edicts
	edict_t		*edicts;			// can NOT be array indexed, because
									// edict_t is variable sized, but can
									// be used to reference the world ent

	int			numentityfields;
	int			*entityfieldofs;
	ddef_t		**entityfields;
} qcvm_t;

typedef struct savedata_s
{
	FILE			*file;
	SDL_atomic_t	abort;			// < 0 = error, > 0 = aborted by user
	char			path[MAX_OSPATH];
	char			comment[SAVEGAME_COMMENT_LENGTH+1];
	char			mapname[64];
	double			time;
	float			spawn_parms[NUM_SPAWN_PARMS];
	int				skill;
	int				numknownstrings;
	const char		**knownstrings;
	int				num_edicts;
	edict_t			*edicts;
	float			*globals;
	const char		*lightstyles[MAX_LIGHTSTYLES];
	byte			*buffer;
	int				buffersize;
} savedata_t;

#define	SAVEGAME_VERSION		5
#define	SAVEGAME_VERSION_KEX	6

extern THREAD_LOCAL globalvars_t	*pr_global_struct;
extern THREAD_LOCAL qcvm_t			*qcvm;

void PR_SwitchQCVM(qcvm_t *nvm);
void PR_PushQCVM(qcvm_t *newvm, qcvm_t **oldvm);
void PR_PopQCVM(qcvm_t *oldvm);

void PR_Init (void);

void PR_ExecuteProgram (func_t fnum);
void PR_ClearProgs(qcvm_t *vm);
qboolean PR_LoadProgs (const char *filename, qboolean fatal);
void PR_EnableExtensions (void);
void PR_AutoCvarChanged (cvar_t *var);					//updates the autocvar_ globals when their cvar is changed
int PR_FindExtensionByName (const char *name);			//returns known extension index, or 0 for unrecognized extensions

void PR_ReloadPics (qboolean purge);					//for gamedir or video changes

const char *PR_GetString (int num);
int PR_SetEngineString (const char *s);
void PR_ClearEngineString (int num);
int PR_AllocString (int bufferlength, char **ptr);

void PR_Profile_f (void);

edict_t *ED_Alloc (void);
void ED_Free (edict_t *ed);
void ED_ClearEdict (edict_t *e);

qboolean ED_IsRelevantField (edict_t *ed, ddef_t *d);
const char *ED_FieldValueString (edict_t *ed, ddef_t *d);
void ED_Print (edict_t *ed);
void ED_Write (savedata_t *save, edict_t *ed);
const char *ED_ParseEdict (const char *data, edict_t *ent);

void ED_WriteGlobals (savedata_t *save);
const char *ED_ParseGlobals (const char *data);

void ED_LoadFromFile (const char *data);

/*
#define EDICT_NUM(n)		((edict_t *)(sv.edicts+ (n)*pr_edict_size))
#define NUM_FOR_EDICT(e)	(((byte *)(e) - sv.edicts) / pr_edict_size)
*/
edict_t *EDICT_NUM(int);
int NUM_FOR_EDICT(edict_t*);
int SAVE_NUM_FOR_EDICT (savedata_t *save, edict_t *e);

#define	NEXT_EDICT(e)		((edict_t *)( (byte *)e + qcvm->edict_size))

#define	EDICT_TO_PROG(e)	(int)((byte *)e - (byte *)qcvm->edicts)
#define PROG_TO_EDICT(e)	((edict_t *)((byte *)qcvm->edicts + e))
#define SAVE_PROG_TO_EDICT(s, e)	((edict_t *)((byte *)s->edicts + e))

#define	G_FLOAT(o)		(qcvm->globals[o])
#define	G_INT(o)		(*(int *)&qcvm->globals[o])
#define	G_EDICT(o)		((edict_t *)((byte *)qcvm->edicts+ *(int *)&qcvm->globals[o]))
#define G_EDICTNUM(o)		NUM_FOR_EDICT(G_EDICT(o))
#define	G_VECTOR(o)		(&qcvm->globals[o])
#define	G_STRING(o)		(PR_GetString(*(string_t *)&qcvm->globals[o]))
#define	G_FUNCTION(o)		(*(func_t *)&qcvm->globals[o])

#define G_VECTORSET(r,x,y,z) do{G_FLOAT((r)+0) = x; G_FLOAT((r)+1) = y;G_FLOAT((r)+2) = z;}while(0)

#define	E_FLOAT(e,o)		(((float*)&e->v)[o])
#define	E_INT(e,o)		(*(int *)&((float*)&e->v)[o])
#define	E_VECTOR(e,o)		(&((float*)&e->v)[o])
#define	E_STRING(e,o)		(PR_GetString(*(string_t *)&((float*)&e->v)[o]))

extern	int		type_size[8];

typedef struct builtindef_s
{
	const char		*name;
	builtin_t		ssqcfunc;
	builtin_t		csqcfunc;
	int				number;
	qcextension_t	ext;
} builtindef_t;

extern builtindef_t	pr_builtindefs[];
extern int			pr_numbuiltindefs;

FUNC_NORETURN void PR_RunError (const char *error, ...) FUNC_PRINTF(1,2);
#ifdef __WATCOMC__
#pragma aux PR_RunError aborts;
#endif

void ED_PrintEdicts (void);
void ED_PrintNum (int ent);

eval_t *GetEdictFieldValue(edict_t *ed, int fldofs);
eval_t *GetEdictFieldValueByName(edict_t *ed, const char *name);

void SaveData_Init (savedata_t *save);
void SaveData_Clear (savedata_t *save);
void SaveData_Fill (savedata_t *save);
void SaveData_WriteHeader (savedata_t *save);

#endif	/* QUAKE_PROGS_H */
