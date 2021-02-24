#ifndef __RCTRACE_H__
#define __RCTRACE_H__

void RCTrace(int nLv,char *format,...);
void InitRCTrace(int argc, char **argv);
void RCTraceLevelManager(char *pInitString);

#endif /* __RCTRACE_H__ */
