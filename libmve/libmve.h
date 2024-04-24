#ifndef _MVELIBW_H
#define _MVELIBW_H

#include "SystemInterfaces.h"
#if defined(__LINUX__)
#include "lnxdsound.h"
#endif


#define MVE_ERR_EOF 1

#define MVE_RM_NORMAL 0

typedef struct{
	int screenWidth;
	int screenHeight;
	int width;
	int height;
	int truecolor;
} MVE_videoSpec;

int  MVE_rmPrepMovie(int stream, int x, int y, int track);
int  MVE_rmStepMovie();
void MVE_rmHoldMovie();
void MVE_rmEndMovie();

void MVE_getVideoSpec(MVE_videoSpec *vSpec);

void MVE_sndInit(void *dev);

typedef unsigned int (*mve_cb_Read)(int stream,
                                    void *buffer,
                                    unsigned int count);

typedef void *(*mve_cb_Alloc)(unsigned int size);
typedef void (*mve_cb_Free)(void *ptr);

typedef void (*mve_cb_ShowFrame)(unsigned char *buffer, unsigned int bufw, unsigned int bufh, unsigned int sx, unsigned int sy, unsigned int sw, unsigned int sh, unsigned int dstx, unsigned int dsty, unsigned int hicolor);

typedef void (*mve_cb_SetPalette)(unsigned char *p,
                                  unsigned int start, unsigned int count);

void MVE_ioCallbacks(mve_cb_Read io_read);
void MVE_memCallbacks(mve_cb_Alloc mem_alloc, mve_cb_Free mem_free);
void MVE_sfCallbacks(mve_cb_ShowFrame showframe);
void MVE_palCallbacks(mve_cb_SetPalette setpalette);

void MVE_rmFastMode(int mode);

typedef struct _MVE_frstream *MVE_frStream;
MVE_frStream MVE_frOpen(unsigned int (*fn_read)(int handle, void *buf, unsigned int count), int handle,
                        int (*fr_callback)(unsigned op, unsigned subop, void *buf));
int MVE_frGet(MVE_frStream frs, unsigned char **pbuf, unsigned int *width, unsigned int *height, unsigned int *hicolor);
void MVE_frPal(MVE_frStream frs, unsigned char **ppal, unsigned int *pstart, unsigned int *pcount);
void MVE_frClose(MVE_frStream frs);
void MVE_ReleaseMem(void);

void MVE_sfSVGA(unsigned w, unsigned h, unsigned LineWidth, unsigned WriteWin, unsigned char *WriteWinPtr,
                unsigned long WinSize, unsigned WinGran, void *SetBank, unsigned hicolor);

#endif /* _LIBMVE_H */
