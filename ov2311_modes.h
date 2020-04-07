/*
OV2311
*/

#ifndef ov2311MODES_H_
#define ov2311MODES_H_

struct sensor_regs ov2311_2MPix[] =
{
	
}

#define addreg(a, b) { a, b }

/*1600X1300*/
struct sensor_regs ov2311_mode1[] =
{
	
}
/*1280X720*/
struct sensor_regs ov2311_mode2[] =
{
	
}
/*6400X480*/
struct sensor_regs ov2311_mode3[] =
{
	
}
struct mode_def ov2311_modes[] = {
   {
      .regs          = ov2311_2MPix,
      .num_regs      = NUM_ELEMENTS(ov2311_2MPix),
      .width         = 1600,
      .height        = 1300,
      .encoding      = 0,
      .order         = BAYER_ORDER_GBRG,
      .native_bit_depth = 10,
      .image_id      = 0x2B,
      .data_lanes    = 2,
      .min_vts       = 1968,
      .line_time_ns  = 32503,
      .timing        = {0, 0, 0, 0, 0},
      .term          = {0, 0},
      .black_level   = 16,
   },
};

#undef addreg

struct sensor_regs ov2311_stop[] = {
   { 0x0100, 0x00 },
};

// ID register settings taken from http://www.mail-archive.com/linux-kernel@vger.kernel.org/msg1298623.html
struct sensor_def ov2311 = {
   .name =                 "ov2311",
   .modes =                ov2311_modes,
   .num_modes =            NUM_ELEMENTS(ov2311_modes),
   .stop =                 ov2311_stop,
   .num_stop_regs =        NUM_ELEMENTS(ov2311_stop),

   .i2c_addr =             0xc0,
   .i2c_addressing =       2,
   .i2c_ident_length =     2,
   .i2c_ident_reg =        0x300A,
   .i2c_ident_value =      0x1123,  //0x5647 byte swapped

   .vflip_reg =            0x3820,
   .vflip_reg_bit =        2,
   .hflip_reg =            0x3821,
   .hflip_reg_bit =        2,

   .exposure_reg =         0x3501,
   .exposure_reg_num_bits = 16,

   .vts_reg =              0x380E,
   .vts_reg_num_bits =     16,      //  total vertical size [15:8] and [7:0] (ov2311 preliminary datasheet is inaccurate)

   .gain_reg =             0x3508,  //  coarse real gain
   .gain_reg_num_bits =    4,
};

#endif
