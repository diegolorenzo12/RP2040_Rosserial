/*
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote prducts derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ROS_RP2040_HARDWARE_H_
#define ROS_RP2040_HARDWARE_H_

class Serial
{
};

class RP2040Hardware
{
public:
  RP2040Hardware(Serial *io, long baud = 115200)
  {
    iostream = io;
    baud_ = baud;
  }
  RP2040Hardware()
  {
    // iostream = &Serial;
    baud_ = 115200;
  }
  RP2040Hardware(RP2040Hardware &h)
  {
    this->iostream = h.iostream;
    this->baud_ = h.baud_;
  }

  void setBaud(long baud)
  {
    this->baud_ = baud;
  }

  int getBaud() { return baud_; }

  void init()
  {
    stdio_init_all();
  }

  int read()
  {
    return getchar_timeout_us(1);
  };

  void write(uint8_t *data, int length)
  {
    for (int i = 0; i < length; i++)
    {
      putchar_raw(data[i]);
    }
  }

  unsigned long time()
  {
    return to_ms_since_boot(get_absolute_time());
  }

protected:
  long baud_;
  Serial *iostream;
};

#endif
