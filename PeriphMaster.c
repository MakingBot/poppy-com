/**
 *  \file PeriphMaster.c
 *  \brief application carteperiph
 *  \details this file is the main application it don't must any reference to any hardware
 */

/**
 * This is the minimal include you will need to use poppy-com in a module
 * application
 */
#include "poppy-com/poppyNetwork.h"
#include <stdint.h>
#include "include/HAL.h" // Hardware abstraction layer
#include "include/globaletypedef.h"
#include "include/PeriphMaster.h"
#include "include/utility.h"
#include "include/init.h"
#include "include/pwm.h"
#include "include/isr.h" //driver of interruption
#include "include/protocole.h"


extern struct data system_data;

/**
 * \fn void rx_cb(msg_dir_t dir, msg_t *msg)
 * \brief Callback function for Slave mode messages reception.
 *
 * \param dir Message direction. (That will be remove!)
 * \param msg Received message.
 */
void rx_cb(msg_dir_t dir, msg_t *msg) {
    /*
     * Add your RX code here.
     */
     set_color(0,0,255,255);
}

/**
 * \fn void rxgc_cb(msg_dir_t dir, msg_t *msg)
 * \brief Callback function for Slave mode messages reception with general call.
 *
 * \param dir Message direction. (That will be remove!)
 * \param msg Received message.
 */
void rxgc_cb(msg_dir_t dir, msg_t *msg) {
    /*
     * Add your RX general call code here.
     */
    /*
     * Add your RX general call code here.
     */
         set_color(255,0,0,255);
}

/**
 * \fn void tx_cb(msg_t *msg)
 * \brief Callback function for Slave mode messages transmission.
 *
 * \param msg Transmitted message. You have to put something in this msg_t.
 */
void tx_cb(msg_t *msg) {
    msg->reg=0x04;
    msg->size =0x01;
    //msg->data= "test";
      set_color(0,255,0,255);
}
/**
 *  \brief main
 *
 *  \return none
 *
 *  \details Details
 */int main()
{

   cli();
     init();
     pwm_init();
     isr_init();
     #ifdef __DEBUG__
    set_color(0,0,255,255); //a priori 25ms d'execution
    #endif // __DEBUG__

    // launchCom();
   sei();
    poppyNetwork_init(tx_cb, rx_cb, rxgc_cb);
   while(1)
   {


  #ifdef __DEBUG__
    set_color(0,0,255,255); //a priori 25ms d'execution
    #endif // __DEBUG__



  #ifdef __DEBUG__
    set_color(255,0,0,255); //a priori 25ms d'execution
    #endif // __DEBUG__



   }
}