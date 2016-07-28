<?php

/**
 * @file
 * CCK Field for Singapore phone numbers.
 */

function phone_sg_metadata() {
  // These strings are translated using t() on output.
  return array(
    'error' => '"%value" is not a valid Singaporean phone number<br>Singaporean phone numbers should only ...',
  );
}

/**
 * Verifies that $phonenumber is valid
 *
 * @param string $phonenumber
 * @return boolean Returns boolean FALSE if the phone number is not valid.
 */
function valid_sg_phone_number($phonenumber) {
  // define regular expression
  /*
    See: http://en.wikipedia.org/wiki/Telephone_numbers_in_Singapore

    Accepts:
        +6561234567  / +6581234567  / +6591234567
        +65 61234567 / +65 81234567 / +65 91234567
        61234567     / 81234567     / 91234567
        +65 6123 4567
  */

  $patterns = array(
    '/^(\+65)?\s?[689]\d{7}$/i',
    '/^(\+65)?\s?[689]\d{3}\s?\d{4}$/i',
  );


  // return true if valid, false otherwise
  foreach ($patterns as $pattern) {
    if (preg_match($pattern, $phonenumber)) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Formatting for Singapore Phone Numbers.
 *
 * @param string $phonenumber
 * @return string Returns a string containting the phone number with some formatting.
 */
function format_sg_phone_number($phonenumber, $field) {

  //$phonenumber = trim($phonenumber);

   // do some formatting on the phone number

/* ==> to be done ==> add the country code 
   if ($field['phone_country_code']) {
      if ($matches[1] != "+39") {
  	$phonenumber = "+39" . " " . $phonenumber;
      }
   }
*/ 
   return $phonenumber;
}
