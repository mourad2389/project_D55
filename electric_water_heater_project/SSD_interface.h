/*
 * SSD_interface.h
 *
 * Created: 11/19/2023 11:29:01 PM
 *  Author: Kareem Hussein
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


/* Macros for SSD Id*/
#define SSD_ONE            1
#define SSD_TWO            2

              /*************** APIS PROTO TYPES ***************/
              
void SSD_init                    (void);
void SSD_displayNumber           (u8 ssdId,u8 desiredNumber);
void SSD_displayMultiNumber      (u8 desiredNumber);
static void private_writeHalfPort(u8 value);


#endif /* SSD_INTERFACE_H_ */