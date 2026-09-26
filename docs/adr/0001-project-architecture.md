# ADR-0001: VDB Initial Architecture

- **Status:** Accepted
- **Date:** 2026-09-26
- **Decision Type:** Architecture

## Context

VDB is being developed as a small educational relational database engine.

The primary objective is to understand the systems underneath a database,
including:

- storage
- memory
- processes
- file I/O
- indexing
- transactions
- concurrency
- networking
- failure recovery

The project must remain small enough to complete while still exposing
important systems concepts.

A production-scale database architecture would introduce unnecessary
complexity for the learning objective.

## Decision

VDB will use a layered architecture:

```text
Client
  ↓
SQL Layer
  ↓
Query Engine
  ↓
Index / Transaction Managers
  ↓
Buffer Pool
  ↓
Storage Engine
  ↓
Filesystem
  ↓
Disk
The initial implementation will be:

- written in C++17
- built with CMake
- developed on Linux/WSL2
- controlled with Git
- initially single-threaded
- initially accessed through a CLI
- based on fixed-size storage pages
- extended later with B+ tree indexing
- extended later with WAL and crash recovery
- extended later with TCP networking
- extended later with concurrent clients

## Scope Strategy

The project will prioritize:

1. Correctness
2. Understandability
3. Testability
4. Failure handling
5. Measurement
6. Performance optimization

Optimization will not be performed before the relevant behavior can be
measured.

## Alternatives Considered

### Build directly on an existing database library

Rejected because it would hide too much of the storage and database
implementation that this project is intended to teach.

### Implement a production-scale database

Rejected because the complexity would exceed the learning objective and
available development time.

### Build every component simultaneously

Rejected because incremental development makes failures easier to isolate
and allows each subsystem to be understood before introducing the next one.

## Consequences

### Positive

- Clear separation between components.
- Individual components can be tested independently.
- OS concepts can be connected directly to database behavior.
- Features can be introduced incrementally.
- The architecture can evolve without requiring the entire system to be
  rewritten.

### Negative

- The project will initially have fewer features than production databases.
- Some implementations will intentionally be simpler than production
  implementations.
- Additional abstraction may introduce code that would not be necessary
  in a very small program.

## Review Conditions

This decision should be revisited if:

- the architecture prevents a required feature from being implemented
  cleanly;
- performance measurements reveal a significant bottleneck;
- a subsystem requires a fundamentally different design;
- the project scope changes substantially.
