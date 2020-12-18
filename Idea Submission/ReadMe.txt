HONDA HACKATHON - TEAM NOMAD
=============================================================================
Introduction: 
- Connecting cars to the digital environment aids in better understanding for the needs of the user and also the user's utilities. 
- It provides a whole new broader perspective in the way we see devices. In case of cars, having the ability to look under the hood without being remotely close to it or performing userless diagnostics is now a reality.
- The introduction to connecting cars have always been the hot topic in the Real-Time based IoT technology. Although technology has it's unique perks in ease of access or understanding your car better, its also a distraction in a way. The overall smart car system must be polished well enough that the system must understand when to/when not to notify the user regarding the data from the car(s). 
=============================================================================
Assumptions: 
- Technology that is currently implemented can perform basic tasks based on user prompt by the Honda Connect application available on Android and iOS platforms. 
- Alexa, an Amazon Assistant AI is also integrated onto the application for voice based services. It also aids in prompting the On-Board Computer (OBC) to perform certain tasks.
- The car uses an E-SIM provided by a particular ISP for communication between the car and the user (even the AWS servers for data logging). This is done via GSM services (SMS) or 4G LTE based Internet accessibility. 
- The particular ISP Honda utilises in their cars need not be uniform across India and hence there might be connectivity issues involved.
The data from the car in run time is logged and sent to the server in time intervals of 3 minutes.
- Companies like Google, Amazon, Apple, Microsoft have polished their respective AI assistant tools. Using a 'built from ground up' AI assistants won't be a ideal solution due to many factors that include linguistic inabilities of some users or the versatility of the AI. - The AI will be unable to pick up the correct questions or queries from the user.  
=============================================================================
Survey and Problems found:
- After the team conducted a literature survey by using the application and traversing through customer reviews on Play Store and App Store, some significant problems were found that hinders the overall perfomance of the application.
- The application when used to track the car in Real-time, The refresh rate is significantly slower than conventional applications. As per research, averaged to 3 minutes max.
- The application that performs diagnosis/check for lights, engine, window, locks have variable response time. This is due to variable network connectivity by the ISP of the car and the user's smartphone.
- Similarly, due to the variability of the connectivity, the user prompt of locking/unlocking, turning engine on/off, opening the trunk, finding the car in a parking lot and so on takes time.
- In areas with no network access, it is technically impossible to utilise any of the features mentioned by the application description.
- GSM based communications are vulnerable to cyber attacks such as bruteforce attacks or rolljam attacks. Depending on the complexity of the code used by the device to authenticate and prompt the car to perform unlocking or even starting the engine, it can be recreated and used to access the car. 
=============================================================================
Non technical solutions:
- Having a dedicated screen in car and in app that types out the given voice command in real-time will comfort the user 
=============================================================================
Our solution to the said Problems:
- The solution to the given problem is represented in a sophisticated flow diagram. The OBC in the current Honda cars are capable of running the said alternative solution. 

- A UI that stores GPS routes with Time (Setting up an Alarm)
- Backend (Predicts Whether the Journey is ideal, based on the datalogs with our Architecture and Also use Google Map API for traffic, ETA, Distance.)
- Fuel status, distance and Milage of the Honda car model will specify if the journey is possible
- Engine check and Honda assist automatically with Car Owner details to nearest Honda service center
- Setup Alerts that are time specific which prompts the user OR automatically performs suitable operation regarding parking and safety check
- In built low power health monitor that checks for the vitality of the OBC and Battery - Safe Mode update the same to AWS and will prompt the user immediately
- AI Prompting the user must be Optional. Optional thing is for various services
=============================================================================

======END OF README======