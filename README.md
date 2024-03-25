# Living Website

We provide a backend framework for creating an adaptable navigation system for websites that updates links automatically based on popularity. This framework can be attached to any website in order to provide a client’s site with more adaptability. Our system improves customer satisfaction when they navigate through our client’s website, while personalizing the user experience. The main function of the framework is an automatically updating navigation bar. Our product will log user activity and track which navigation items are accessed most often. It will use this information to reorder the items in the navbar based on popularity. The project also includes an example website to demonstrate the functionality of the framework. The current version of the framework can log user activity and send that information to the database. It can also generate updated HTML files based on user activity, though currently they have to be manually applied.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

* Any C++ Compiler or IDE  
  * LibGit2 C++ Library for work on release 2
* Git installed on your machine
* A microsoft azure account for editing the example website (free tier)

### Installing

  Simply download the raw files from github, no installation required.

## Running the tests

We use try/catch to allow the program to run through a series of tests and print out any tests that failed/succeeded and fix bugs from within the program. The test files are stored separately from the main C++ code in the folder found [here](PASTETHELINKHERE.please). You can compile and run the tests the same as the other C++ code.

## Built With

* [Azure](https://azure.microsoft.com/en-us): Blob storage and static website hosting
* [MySQL](https://www.mysql.com/): Database hosting and connection

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/jk2429/Living-Website/tags). 

## Authors

See the list of [contributors](https://github.com/jk2429/Living-Website/graphs/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](/LICENSE) file for details

The template for this document is from [this repository](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2).