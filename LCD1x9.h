#ifndef _LCD1x9_DRIVER_H
#define _LCD1x9_DRIVER_H


class LCD1x9 {
  static unsigned char lcdBitmap[20]; // 40segments * 4 = 160px, 160 / 8 = 20bytes

public:
  /******************************************************************************
  * Description: LCD1x9_Initialize(..) - initializes pins and registers of the LCD1x9
  *				Also lights up all segments
  * Input: 	none
  * Output: 	none
  * Return:	0 if sucessfully initialized, -1 if error occured 
  *******************************************************************************/
  void initialize();
  void initialize(int address);
  
  /******************************************************************************
  * Description: LCD1x9_enableSegment(..) - enables a segment in the display buffer
  *		Note: Does not actually light up the segment, have to call the 'LCD1x9_Update(..)'
  * Input: 	comIndex - backplate index
  *			bitIndex - segment index
  * Output: 	none
  * Return:	none
  *******************************************************************************/
  void enableSegment(unsigned char comIndex, unsigned char bitIndex);
  
  /******************************************************************************
  * Description: LCD1x9_disableSegment(..) - disables a segment in the display buffer
  *		Note: Does not actually lights off the segment, have to call the 'LCD1x9_Update(..)'
  * Input: 	comIndex - backplate index
  *			bitIndex - segment index
  * Output: 	none
  * Return:	none
  *******************************************************************************/
  void disableSegment(unsigned char comIndex, unsigned char bitIndex);
  
  /******************************************************************************
  * Description: LCD1x9_Update(..) - disables a segment in the display buffer
  *		Note: Does not actually lights off the segment, have to call the 'LCD1x9_Update(..)'
  * Input: 	comIndex - backplate index
  *			bitIndex - segment index
  * Output: 	none
  * Return:	none
  *******************************************************************************/
  void update(void);
  
  /******************************************************************************
  * Description: LCD1x9_Write(..) - writes a string to the display
  * Input: 	string - the string to write, no more than 9 characters
  *			bitIndex - segment index
  * Output: 	none
  * Return:	none
  *******************************************************************************/
  void write(char *string);
};

#endif // _LCD1x9_DRIVER_H


