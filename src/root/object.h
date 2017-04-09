
/* Copyright (c) 1999-2014 by Digital Mars
 * All Rights Reserved, written by Walter Bright
 * http://www.digitalmars.com
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
 * https://github.com/D-Programming-Language/dmd/blob/master/src/root/object.h
 */

#ifndef OBJECT_H
#define OBJECT_H

#define POSIX (__linux__ || __APPLE__ || __FreeBSD__ || __OpenBSD__ || __sun || __HAIKU__)

#if __DMC__
#pragma once
#endif

#include <stddef.h>

typedef size_t hash_t;

struct OutBuffer;

/*
 * Root of our class library.
 */
class RootObject
{
public:
    RootObject() { }

    virtual bool equals(RootObject *o);

    /**
     * Return <0, ==0, or >0 if this is less than, equal to, or greater than obj.
     * Useful for sorting Objects.
     */
    virtual int compare(RootObject *obj);

    /**
     * Pretty-print an Object. Useful for debugging the old-fashioned way.
     */
    virtual void print();

    virtual char *toChars();
    virtual void toBuffer(OutBuffer *buf);

    /**
     * Used as a replacement for dynamic_cast. Returns a unique number
     * defined by the library user. For Object, the return value is 0.
     */
    virtual int dyncast();
};

#endif
