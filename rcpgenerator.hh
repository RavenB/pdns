/*
    PowerDNS Versatile Database Driven Nameserver
    Copyright (C) 2005  PowerDNS.COM BV

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2 as 
    published by the Free Software Foundation

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef PDNS_RCPGENERATOR_HH
#define PDNS_RCPGENERATOR_HH

#include <string>
#include <stdexcept>
#include <stdint.h>

using namespace std;

class RecordTextException : public runtime_error
{
public:
  RecordTextException(const string& str) : runtime_error(str)
  {}
};

class RecordTextReader
{
public:
  RecordTextReader(const string& str, const string& zone="");
  void xfr32BitInt(uint32_t& val);
  void xfr16BitInt(uint16_t& val);
  void xfr8BitInt(uint8_t& val);

  void xfrType(uint16_t& val);
  void xfrIP(uint32_t& val);
  void xfrTime(uint32_t& val);

  void xfrLabel(string& val, bool compress=false);
  void xfrText(string& val);
  void xfrHexBlob(string& val);
  void xfrBlob(string& val);

  bool eof();
private:
  string d_string;
  string d_zone;
  string::size_type d_pos;
  string::size_type d_end;
  void skipSpaces();
};

class RecordTextWriter
{
public:
  RecordTextWriter(string& str);
  void xfr32BitInt(const uint32_t& val);
  void xfr16BitInt(const uint16_t& val);
  void xfr8BitInt(const uint8_t& val);
  void xfrIP(const uint32_t& val);
  void xfrTime(const uint32_t& val);

  void xfrType(const uint16_t& val);
  void xfrLabel(const string& val, bool compress=false);
  void xfrText(const string& val);
  void xfrBlob(const string& val);
  void xfrHexBlob(const string& val);

private:
  string& d_string;
};


#endif
