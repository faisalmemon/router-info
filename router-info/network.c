//
//  network.c
//  router-info
//
//  Created by Faisal Memon on 07/03/2020.
//  Copyright © 2020 Faisal Memon. All rights reserved.
//

#include "network.h"

#include <ifaddrs.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <string.h>
#import <netdb.h>

extern int errno;

char *routerInfo_getRouterAddress(void) {
    char *router_address = NULL;
    int success = 0;
    
    struct ifaddrs *interfaces = NULL;
    success = getifaddrs(&interfaces);
    
    if (success != 0) {
        char *error = strerror(errno);
        fprintf(stderr, "Get interface addresses returned %s\n", error);
        return NULL;
    }
    
    
    return NULL;
}


/*

- (NSString *)getRouterAddress {
    std::string router_address;
    struct ifaddrs *interfaces = NULL;
    int success = 0;
    success = getifaddrs(&interfaces);
    if (success == 0) {
        struct ifaddrs *temp_addr = interfaces;
        for (temp_addr = interfaces; temp_addr != NULL; temp_addr =  temp_addr->ifa_next) {
            if (!(temp_addr->ifa_flags & IFF_UP) || (temp_addr->ifa_flags & IFF_LOOPBACK) || (std::string(temp_addr->ifa_name) != "en0")) {
                continue;
            }

            char naddr[INET6_ADDRSTRLEN];
            char nmask[INET6_ADDRSTRLEN];
            char ngate[INET6_ADDRSTRLEN];
            int ipversion = temp_addr->ifa_addr->sa_family;
            inet_ntop(ipversion,&((struct sockaddr_in *)temp_addr->ifa_addr)->sin_addr, naddr, INET6_ADDRSTRLEN);
            std::string ip_address(naddr);
            if ((struct sockaddr_in6 *)temp_addr->ifa_netmask != NULL) {
              inet_ntop(ipversion,&((struct sockaddr_in *)temp_addr->ifa_netmask)->sin_addr, nmask, INET6_ADDRSTRLEN);
            }
            if ((struct sockaddr_in6 *)temp_addr->ifa_dstaddr != NULL) {
              inet_ntop(ipversion,&((struct sockaddr_in *)temp_addr->ifa_dstaddr)->sin_addr, ngate, INET6_ADDRSTRLEN);
            }

            // Until here the logic is perfectly working and I am able to the variable  ip_address populated with the correct IP address. But following is the
            // code that does not work. How to get the router IP address from here ???
            if (ip_address.find("192.168.") != std::string::npos) { // My IP address is generally in the 192.168 range. Its an ad hoc wifi
                struct hostent *he;
                he = gethostbyaddr(&((struct sockaddr_in *)temp_addr->ifa_addr)->sin_addr, sizeof (((struct sockaddr_in *)temp_addr->ifa_addr)->sin_addr), AF_INET);
                if (he) {
                    router_address = std::string(he->h_name);
                }
            }
        }
    }
    freeifaddrs(interfaces);

    NSString *router_address_nsstring = [NSString stringWithCString:router_address.c_str() encoding:[NSString defaultCStringEncoding]];
    return router_address_nsstring;
}
 */