#!/usr/bin/env bash
dfu-programmer atmega32u4 erase --force && dfu-programmer atmega32u4 flash dz60_dz60_pkieltyka.hex

