//crc.h

#ifndef  _CRC_H_

#define  _CONST_  const //51用code，其它用 const

#ifndef  uint8 
#define  uint8    unsigned char
#endif   /* #ifndef  uint8 */

#ifndef  uint16
#define  uint16   unsigned short
#endif  /* #ifndef  uint16 */


/*******************************************************************************
* Function Name  : UART_CRC16
* Description    : 2bytes CRC value calculate
* 参数      : px-数据；
*             ucLen-数据长度
* 返回      : CRC16校验码
*******************************************************************************/
uint16 CRC16(uint8 *px, uint16 ucLen);


#endif  /* #ifndef  _CRC_H_ */
