# SNOW-CRASH

This repository contains my work on the Snow Crash project, an introduction to cybersecurity challenges where each level required discovering and exploiting vulnerabilities to progress to the next step.

### Project Overview
The goal of this project was to:
- Understand and exploit system vulnerabilities.
- Develop problem-solving skills to bypass various security restrictions.
- Master tools like SSH, SCP, and scripting to automate or simplify tasks.
- Demonstrate autonomy and logical thinking to overcome roadblocks.

Each level corresponds to a specific challenge, where I had to retrieve a password to log into the next account (flagXX) using a variety of techniques.

### **Project Description**

In this project, I worked through multiple levels, each requiring me to exploit system vulnerabilities in order to obtain a password for the next level's account. The challenges tested my ability to:  
- Identify and exploit vulnerabilities in various systems.  
- Use tools like **SSH**, **SCP**, and command-line techniques to bypass restrictions.  
- Develop logic and problem-solving skills for real-world security scenarios.


### **How to Use This Repository**

The repository is organized as follows:  

```bash
project_repo/
├── level00/
│   ├── flag          # Password or proof of success for level00
│   └── resources/    # Scripts, commands, and explanations
├── level01/
│   ├── flag
│   └── resources/
├── level02/
│   ├── flag
│   └── resources/
└── ...
```

For each level, you'll find:
- The **flag file**, which contains the password/token to progress to the next level.
- The **resources folder**, which contains files or scripts used to solve the challenge.

### **Objectives**
- **Understand system vulnerabilities** and develop strategies to exploit them.  
- **Use various tools** like SSH, SCP, and scripting to automate tasks and bypass security mechanisms.  
- **Develop problem-solving abilities** to overcome roadblocks and think logically under pressure.

### **Instructions**
1. Set up a VM (64-bit) and start it using the provided ISO.
2. SSH into the VM using the following credentials:  
   ```bash
   ssh level00@192.168.16.128 -p 4242

    Each level requires retrieving the password for the corresponding flagXX account by solving the challenge.
    Once completed, submit the results with a clear explanation of the solution, if needed.
   ```
Each level requires retrieving the password for the corresponding flagXX account by solving the challenge.
Once completed, submit the results with a clear explanation of the solution, if needed.
