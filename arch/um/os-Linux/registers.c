/*
 * Copyright (C) 2004 PathScale, Inc
 * Copyright (C) 2004 - 2007 Jeff Dike (jdike@{addtoit,linux.intel}.com)
 * Licensed under the GPL
 */

#include <errno.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sysdep/ptrace.h>
#include <sysdep/ptrace_user.h>
#include <registers.h>

int save_registers(int pid, struct uml_pt_regs *regs)
{
	int err;

	err = ptrace(PTRACE_GETREGS, pid, 0, regs->gp);
	if (err < 0)
		return -errno;
	return 0;
}

<<<<<<< HEAD
int restore_registers(int pid, struct uml_pt_regs *regs)
=======
int restore_pid_registers(int pid, struct uml_pt_regs *regs)
>>>>>>> 7f08ecfbf357 (Merge tag 'v4.14.270' of https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux into upstream)
{
	int err;

	err = ptrace(PTRACE_SETREGS, pid, 0, regs->gp);
	if (err < 0)
		return -errno;
	return 0;
}

/* This is set once at boot time and not changed thereafter */

static unsigned long exec_regs[MAX_REG_NR];
static unsigned long exec_fp_regs[FP_SIZE];

<<<<<<< HEAD
int init_registers(int pid)
=======
int init_pid_registers(int pid)
>>>>>>> 7f08ecfbf357 (Merge tag 'v4.14.270' of https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux into upstream)
{
	int err;

	err = ptrace(PTRACE_GETREGS, pid, 0, exec_regs);
	if (err < 0)
		return -errno;

	arch_init_registers(pid);
	get_fp_registers(pid, exec_fp_regs);
	return 0;
}

void get_safe_registers(unsigned long *regs, unsigned long *fp_regs)
{
	memcpy(regs, exec_regs, sizeof(exec_regs));

	if (fp_regs)
		memcpy(fp_regs, exec_fp_regs, sizeof(exec_fp_regs));
}
