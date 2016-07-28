<?php

/**
 * @file
 * CCK Field for China phone numbers.
 */

function phone_cn_metadata() {
  // These strings are translated using t() on output.
  return array(
    'error' => '"%value" is not a valid Chinese phone number!<br>Chinese phone numbers should ...',
  );
}

/**
 * Verifies that $phonenumber is a valid Chinese phone number
 *
 * @param string $phonenumber
 * @return boolean Returns boolean FALSE if the phone number is not valid.
 */
function valid_cn_phone_number($phonenumber) {

  $phonenumber = trim($phonenumber);

  // define regular expression
  $patterns = array(
    '/^(\+86|86)?( |-)?([0-9]{11}|([0-9]{3,4}(\-|\.| )[0-9]{3,8})|[0-9]{2}( |\-)[0-9]{4}[ ][0-9]{4}|[0-9]{2}\.[0-9]{2}\.[0-9]{2}\.[0-9]{2}\.[0-9]{2})$/',
    '/^\+86\s?\d{6}\s?\d{4}$/',
    '/^\+86\s?\d{3}\s?\d{4}\s?\d{4}$/',
    '/^\+86\s?\d{2}\s?\d{2}\s?\d{3}\s?\d{3}$/',
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
 * Convert a valid Chinese phone number into standard ... format
 *
 * @param $phonenumber must be a valid number (with optional international prefix)
 *
 */
function format_cn_phone_number($phonenumber, $field) {

  return $phonenumber;
}
