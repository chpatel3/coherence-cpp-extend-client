/*
 * Copyright (c) 2000, 2020, Oracle and/or its affiliates.
 *
 * Licensed under the Universal Permissive License v 1.0 as shown at
 * http://oss.oracle.com/licenses/upl.
 */
#ifndef COH_POSIX_USER_HPP
#define COH_POSIX_USER_HPP

#include "coherence/lang/compatibility.hpp"

#include "private/coherence/native/NativeUser.hpp"

#include <unistd.h>
#include <pwd.h>

COH_OPEN_NAMESPACE2(coherence,native)

String::View NativeUser::getUserName()
    {
    struct passwd pwent;
    struct passwd *pwentp;
    char   buf[1024];

    if (getpwuid_r(getuid(), &pwent, buf, (int) sizeof(buf), &pwentp))
        {
        return NULL;
        }
    else
        {
        return String::create(pwent.pw_name);
        }
    }

COH_CLOSE_NAMESPACE2

#endif // COH_POSIX_USER_HPP
