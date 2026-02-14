*** Settings ***
Library    serial_lib.py
Suite Setup    Open Port    ${PORT}
Suite Teardown    Close Port

*** Variables ***
${PORT}    COM6

*** Test Cases ***
SYNC ON Test
    Send Command    SYNC_ON
    ${resp}=    Read Response
    Should Be Equal    ${resp}    ACK_ON

SYNC OFF Test
    Send Command    SYNC_OFF
    ${resp}=    Read Response
    Should Be Equal    ${resp}    ACK_OFF

Ping Test
    Send Command    PING
    ${resp}=    Read Response
    Should Be Equal    ${resp}    PONG

PI Command Test
    Send Command    .pi
    ${resp}=    Read Response
    Should Contain    ${resp}    PI

Reboot Test
    Send Command    .reboot
    ${resp}=    Read Response
    Should Be Equal    ${resp}    REBOOTING...