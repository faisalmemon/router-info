//
//  debugDetector.h
//  router-info
//
//  Created by Faisal Memon on 09/03/2020.
//  Copyright © 2020 Faisal Memon. All rights reserved.
//

#ifndef debugDetector_h
#define debugDetector_h

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/sysctl.h>

extern bool AmIBeingDebugged(void);

#endif /* debugDetector_h */
