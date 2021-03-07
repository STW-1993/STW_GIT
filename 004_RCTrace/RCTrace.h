#ifndef __RCTRACE_H__
#define __RCTRACE_H__

#define G_ARR_NUM 20

#if 1           //1：打开RCTrace打印，0：关闭RCTrace打印
#define RCTrace RCTraceDBG
#else
#define RCTrace(x...)
#endif

void RCTraceDBG(int nLv,char *format,...);
void InitRCTrace(int argc, char **argv);
void RCTraceLevelManager(char *pInitString);

#endif /* __RCTRACE_H__ */
