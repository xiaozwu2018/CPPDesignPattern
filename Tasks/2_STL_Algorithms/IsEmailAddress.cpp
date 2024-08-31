/**************************************************************************************************
*
* \file IsEmailAddress.cpp
* \brief C++ Training - Algorithm Programming Example
*
* Copyright (C) 2015-2024 Klaus Iglberger - All Rights Reserved
*
* This file is part of the C++ training by Klaus Iglberger. The file may only be used in the
* context of the C++ training or with explicit agreement by Klaus Iglberger.
*
* Task: Implement the 'is_email_address()' algorithm, which determines whether the given
*       email address is valid. An email address should be considered valid, if the following
*       properties hold:
*        - the address must contain exactly one '@' symbol
*        - both the part before and the part after the '@' symbol ...
*           - ... must contain only alphanumeric characters, dots, or underscores
*           - ... must not start or end with a dot
*           - ... must not contain consecutive dots (e.g. "..")
*        - the part after the '@' symbol must contain at least one dot
*
**************************************************************************************************/


//---- <EmailAddress.h> ---------------------------------------------------------------------------

#include <algorithm>
#include <cstddef>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>


// TODO: Implement the 'is_email_address()' algorithm, which determines whether the given
//       email address is valid. An email address should be considered valid, if the following
//       properties hold:
//        - the address must contain exactly one '@' symbol
//        - both the part before and the part after the '@' symbol ...
//           - ... must contain only alphanumeric characters, dots, or underscores
//           - ... must not start or end with a dot
//           - ... must not contain consecutive dots (e.g. "..")
//        - the part after the '@' symbol must contain at least one dot
//constexpr bool is_email_address( ... )
//{}


class EmailAddress
{
 public:
   explicit EmailAddress( std::string address )
      : address_{std::move(address)}
   {
      if( !is_valid() ) {
         throw std::invalid_argument( "Invalid email address" );
      }
   }

   // ... Other member functions

   std::string const& value() const { return address_; }
   bool is_valid() const
   {
      // TODO: use the 'is_email_address()' algorithm to check 'address_'
      return true;
   }

 private:
   std::string address_;
};

std::ostream& operator<<( std::ostream& os, EmailAddress const& address )
{
   return os << address.value() << " (" << ( address.is_valid() ? "valid" : "INVALID" ) << ')';
}


//---- <Main.cpp> ---------------------------------------------------------------------------------

//#include <EmailAddress.h>
#include <cstdlib>
#include <iostream>


int main()
{
   // Checking invalid email addresses
   try {
      EmailAddress address{ "" };
      std::cerr << "INVALID EMAIL 1 ACCEPTED!\n";
   }
   catch( std::invalid_argument const& ex ) {}

   try {
      EmailAddress address{ "@gmx.de" };
      std::cerr << "INVALID EMAIL 2 ACCEPTED!\n";
   }
   catch( std::invalid_argument const& ex ) {}

   try {
      EmailAddress address{ "klaus.iglberger@" };
      std::cerr << "INVALID EMAIL 3 ACCEPTED!\n";
   }
   catch( std::invalid_argument const& ex ) {}

   try {
      EmailAddress address{ "klaus.@gmx.de" };
      std::cerr << "INVALID EMAIL 4 ACCEPTED!\n";
   }
   catch( std::invalid_argument const& ex ) {}

   try {
      EmailAddress address{ ".iglberger@gmx.de" };
      std::cerr << "INVALID EMAIL 5 ACCEPTED!\n";
   }
   catch( std::invalid_argument const& ex ) {}

   try {
      EmailAddress address{ "klaus..iglberger@gmx.de" };
      std::cerr << "INVALID EMAIL 6 ACCEPTED!\n";
   }
   catch( std::invalid_argument const& ex ) {}

   try {
      EmailAddress address{ "klaus.iglberger@.de" };
      std::cerr << "INVALID EMAIL 7 ACCEPTED!\n";
   }
   catch( std::invalid_argument const& ex ) {}

   try {
      EmailAddress address{ "klaus.iglberger@gmx." };
      std::cerr << "INVALID EMAIL 8 ACCEPTED!\n";
   }
   catch( std::invalid_argument const& ex ) {}

   try {
      EmailAddress address{ "klaus.iglberger@gmx..de" };
      std::cerr << "INVALID EMAIL 9 ACCEPTED!\n";
   }
   catch( std::invalid_argument const& ex ) {}

   try {
      EmailAddress address{ "klaus.iglberger@@gmx.de" };
      std::cerr << "INVALID EMAIL 10 ACCEPTED!\n";
   }
   catch( std::invalid_argument const& ex ) {}

   try {
      EmailAddress address{ "klaus@iglberger@gmx.de" };
      std::cerr << "INVALID EMAIL 11 ACCEPTED!\n";
   }
   catch( std::invalid_argument const& ex ) {}

   try {
      EmailAddress address{ "klaus.iglberger@gmx" };
      std::cerr << "INVALID EMAIL 12 ACCEPTED!\n";
   }
   catch( std::invalid_argument const& ex ) {}

   // Checking valid email addresses
   try {
      EmailAddress address{ "klaus@gmx.de" };
   }
   catch( std::invalid_argument const& ex ) {
      std::cerr << "VALID EMAIL 1 REJECTED: " << ex.what() << "\n";
   }

   try {
      EmailAddress address{ "klaus.iglberger@gmx.de" };
   }
   catch( std::invalid_argument const& ex ) {
      std::cerr << "VALID EMAIL 2 REJECTED: " << ex.what() << "\n";
   }

   try {
      EmailAddress address{ "klaus_iglberger@gmx.de" };
   }
   catch( std::invalid_argument const& ex ) {
      std::cerr << "VALID EMAIL 3 REJECTED: " << ex.what() << "\n";
   }

   return EXIT_SUCCESS;
}
