#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) 
{
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(celcius < 200.0f) 
    {
        return 200;     // Return 200 for ok
    }
    else
    {
        return 500;    // Return 500 for ok
    }
}

float ConvertFarenheitToCelsius(float farenheit)
{
    return (farenheit - 32) * 5 / 9;
}

void alertInCelcius(float farenheit) 
{
    float celcius = ConvertFarenheitToCelsius(farenheit);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) 
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() 
{
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(212.7);
    assert(alertFailureCount == 0);
    
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
