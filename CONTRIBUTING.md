<!-- omit in toc -->
# Contributing to RayMaze

First off, thanks for taking the time to contribute! ❤️

The following is a set of guidelines for contributing to RayMaze. These are mostly guidelines, not rules. Use your best judgment, and feel free to propose changes to this document in a pull request.

All types of contributions are encouraged and valued. See the [Table of Contents](#table-of-contents) for different ways to help and details about how this project handles them. Please make sure to read the relevant section before making your contribution. It will make it a lot easier for us maintainers and smooth out the experience for all involved. The community looks forward to your contributions. 🎉

> And if you like the project, but just don't have time to contribute, that's fine. There are other easy ways to support the project and show your appreciation, which we would also be very happy about:
>
> - Star the project
> - Tweet about it
> - Refer this project in your project's readme
> - Mention the project at local meetups and tell your friends/colleagues

<!-- omit in toc -->
## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [I Have a Question](#i-have-a-question)
- [I Want To Contribute](#i-want-to-contribute)
  - [Reporting Bugs](#reporting-bugs)
  - [Suggesting Enhancements](#suggesting-enhancements)
  - [Your First Code Contribution](#your-first-code-contribution)
  - [Improving The Documentation](#improving-the-documentation)
- [Styleguides](#styleguides)
  - [Commit Messages](#commit-messages)
- [Join The Project Team](#join-the-project-team)
- [Attribution](#attribution)

## Code of Conduct

This project and everyone participating in it is governed by the
[RayMaze Code of Conduct](CODE_OF_CONDUCT.md).
By participating, you are expected to uphold this code. Please report unacceptable behavior
to <midesuperbest@gmail.com>.

## I Have a Question

> If you want to ask a question, we assume that you have read the available [Documentation](https://github.com/AyomideA-S/RayMaze/blob/main/README.md).

Before you ask a question, it is best to search for existing [Issues](https://github.com/AyomideA-S/RayMaze/issues) that might help you. In case you have found a suitable issue and still need clarification, you can write your question in this issue. It is also advisable to search the internet for answers first.

If you then still feel the need to ask a question and need clarification, we recommend the following:

- Open an [Issue](https://github.com/AyomideA-S/RayMaze/issues/new).
- Provide as much context as you can about what you're running into.
- Provide project and platform versions (e.g., OS, compiler, SDL version), depending on what seems relevant.

We will then take care of the issue as soon as possible.

## I Want To Contribute

> ### Legal Notice <!-- omit in toc -->
>
> When contributing to this project, you must agree that you have authored 100% of the content, that you have the necessary rights to the content and that the content you contribute may be provided under the project license.

### Reporting Bugs

This section guides you through submitting a bug report for RayMaze. Following these guidelines helps maintainers and the community understand your report, reproduce the behavior, and find related reports.

<!-- omit in toc -->
#### Before Submitting a Bug Report

A good bug report shouldn't leave others needing to chase you up for more information. Therefore, we ask you to investigate carefully, collect information and describe the issue in detail in your report. Please complete the following steps in advance to help us fix any potential bug as fast as possible.

- Make sure that you are using the latest version.
- Determine if your bug is really a bug and not an error on your side (e.g., using incompatible environment components/versions). Make sure that you have read the [documentation](https://github.com/AyomideA-S/RayMaze/blob/main/README.md). If you are looking for support, you might want to check [this section](#i-have-a-question).
- To see if other users have experienced (and potentially already solved) the same issue you are having, check if there is not already a bug report existing for your bug or error in the [bug tracker](https://github.com/AyomideA-S/RayMaze/issues?q=label%3Abug).
- Also make sure to search the internet (including [Stack Overflow](https://stackoverflow.com/)) to see if users outside of the GitHub community have discussed the issue.
- Collect information about the bug:
  - Stack trace (Traceback)
  - OS, Platform and Version (Windows, Linux, macOS, x86, ARM)
  - Version of the interpreter, compiler, SDK, runtime environment, package manager, depending on what seems relevant.
  - Possibly your input and the output
  - Can you reliably reproduce the issue? And can you also reproduce it with older versions?

<!-- omit in toc -->
#### How Do I Submit a Good Bug Report?

> You must never report security related issues, vulnerabilities or bugs including sensitive information to the issue tracker, or elsewhere in public. Instead, sensitive bugs must be sent by email to <midesuperbest@gmail.com>.

We use GitHub issues to track bugs and errors. If you run into an issue with the project:

- Open an [Issue](https://github.com/AyomideA-S/RayMaze/issues/new). (Since we can't be sure at this point whether it is a bug or not, we ask you not to talk about a bug yet and not to label the issue.)
- Explain the behavior you would expect and the actual behavior.
- Please provide as much context as possible and describe the *reproduction steps* that someone else can follow to recreate the issue on their own. This usually includes your code. For good bug reports, you should isolate the problem and create a reduced test case.
- Provide the information you collected in the previous section.

Once it's filed:

- The project team will label the issue accordingly.
- A team member will try to reproduce the issue with your provided steps. If there are no reproduction steps or no obvious way to reproduce the issue, the team will ask you for those steps and mark the issue as needs-repro. Bugs with the needs-repro tag will not be addressed until they are reproduced.
- If the team is able to reproduce the issue, it will be marked needs-fix, as well as possibly other tags (such as critical), and the issue will be left to be [implemented by someone](#your-first-code-contribution).

### Suggesting Enhancements

This section guides you through submitting an enhancement suggestion for RayMaze, **including completely new features and minor improvements to existing functionality**. Following these guidelines will help maintainers and the community to understand your suggestion and find related suggestions.

<!-- omit in toc -->
#### Before Submitting an Enhancement

- Make sure that you are using the latest version.
- Read the [documentation](https://github.com/AyomideA-S/RayMaze/blob/main/README.md) carefully and find out if the functionality is already covered, maybe by an individual configuration.
- Perform a [search](https://github.com/AyomideA-S/RayMaze/issues) to see if the enhancement has already been suggested. If it has, add a comment to the existing issue instead of opening a new one.
- Find out whether your idea fits with the scope and aims of the project. It's up to you to make a strong case to convince the project's developers of the merits of this feature. Keep in mind that we want features that will be useful to the majority of our users and not just a small subset. If you're just targeting a minority of users, consider writing an add-on/plugin library.

<!-- omit in toc -->
#### How Do I Submit a Good Enhancement Suggestion?

Enhancement suggestions are tracked as [GitHub issues](https://github.com/AyomideA-S/RayMaze/issues).

- Use a **clear and descriptive title** for the issue to identify the suggestion.
- Provide a **step-by-step description of the suggested enhancement** in as many details as possible.
- **Describe the current behavior** and **explain which behavior you expected to see instead** and why. At this point, you can also tell which alternatives do not work for you.
- You may want to **include screenshots and animated GIFs** which help you demonstrate the steps or point out the part which the suggestion is related to. You can use [this tool](https://www.cockos.com/licecap/) to record GIFs on macOS and Windows, and [this tool](https://github.com/colinkeenan/silentcast) or [this tool](https://github.com/GNOME/byzanz) on Linux.
- **Explain why this enhancement would be useful** to most RayMaze users. You may also want to point out the other projects that solved it better and which could serve as inspiration.

### Your First Code Contribution

#### Setup of Environment, IDE, and Typical Getting Started Instructions

1. **Fork the Repository**: Go to the [RayMaze GitHub repository](https://github.com/AyomideA-S/RayMaze) and click the "Fork" button at the top right to create your own copy of the repository.

2. **Clone the Repository**: Clone your forked repository to your local machine using the following command:

    ```bash
    git clone https://github.com/yourusername/raymaze.git
    cd raymaze
    ```

3. **Install Dependencies**: Install the necessary dependencies. For example, if you are using `make`:

    ```bash
    make install
    ```

4. **Build the Project**: Build the project using the provided `Makefile`:

    ```bash
    make
    ```

5. **Run the Project**: Run the project to ensure everything is set up correctly:

    ```bash
    ./raymaze
    ```

6. **Set Up Your IDE**: Configure your preferred IDE (e.g., [Visual Studio Code](https://code.visualstudio.com/), [CLion](https://www.jetbrains.com/clion/)) to work with the project. Ensure it supports C and [SDL2](https://www.libsdl.org/) development.

7. **Create a New Branch**: Before making any changes, create a new branch for your feature or bug fix:

    ```bash
    git checkout -b feature/your-feature-name
    ```

8. **Make Your Changes**: Implement your changes in the codebase.

9. **Run Tests**: Ensure all tests pass after your changes. If there are no tests, consider writing some.

10. **Commit Your Changes**: Commit your changes with a meaningful commit message:

    ```bash
    git add .
    git commit -m "Add feature/your-feature-name"
    ```

11. **Push Your Changes**: Push your changes to your forked repository:

    ```bash
    git push origin feature/your-feature-name
    ```

12. **Create a Pull Request**: Go to the original repository and create a pull request from your forked repository.

### Improving The Documentation

1. **Identify Areas for Improvement**: Review the existing documentation and identify areas that need updates, improvements, or corrections.

2. **Make Changes Locally**: Clone the repository and make changes to the documentation files (e.g., `README.md`, `CONTRIBUTING.md`).

3. **Follow Documentation Style**: Ensure your documentation follows the project's style guide and is clear and concise.

4. **Commit Your Changes**: Commit your changes with a meaningful commit message:

    ```bash
    git add .
    git commit -m "Improve documentation for [specific section]"
    ```

5. **Push Your Changes**: Push your changes to your forked repository:

    ```bash
    git push origin feature/improve-documentation
    ```

6. **Create a Pull Request**: Go to the original repository and create a pull request from your forked repository.

## Styleguides

### Commit Messages

1. **Use Meaningful Titles**: The title should be a concise summary of the changes made. For example:

    ```bash
    git commit -m "Fix player movement bug"
    ```

2. **Use the Imperative Mood**: Write commit messages in the imperative mood. For example:

    ```bash
    git commit -m "Add new feature for maze generation"
    ```

3. **Provide Context**: If necessary, provide additional context in the body of the commit message. Separate the title and body with a blank line. For example:

    ```bash
    git commit -m "Refactor rendering engine

    This refactor improves the performance of the rendering engine by optimizing the raycasting algorithm."
    ```

4. **Reference Issues**: If your commit addresses an issue, reference it in the commit message. For example:

    ```bash
    git commit -m "Fix player movement bug

    Resolves #42"
    ```

## Join The Project Team

1. **Express Interest**: If you are interested in joining the project team, start by contributing to the project. Make meaningful contributions and engage with the community.

2. **Contact Maintainers**: Reach out to the project maintainers via email or [GitHub issues](https://docs.github.com/en/issues) expressing your interest in joining the team. Provide examples of your contributions and explain why you want to join.

3. **Review Process**: The maintainers will review your contributions and engagement with the project. If they find you a good fit, they will invite you to join the project team.

4. **Onboarding**: Once invited, follow the onboarding process provided by the maintainers. This may include setting up additional permissions, understanding team workflows, and getting familiar with the project's long-term goals.

## Attribution

This guide is based on the **contributing-gen**. [Make your own](https://github.com/bttger/contributing-gen)!
