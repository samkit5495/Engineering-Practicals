package com.se.state;

public class Document {
	private String title;
	private String content;
	private State state = State.REQUESTED;

	public Document(String title, String content) {
		super();
		this.title = title;
		this.content = content;
	}

	public void acquire() {
		if (this.getState().equals(State.REQUESTED)
				|| this.getState().equals(State.REJECTED)) {
			System.out.println("Document " + getTitle() + " is Acquired");
			setState(State.IN_PROGRESS);
		}
	}

	public void write(boolean done) {
		if (this.getState().equals(State.IN_PROGRESS)) {
			if (done) {
				System.out.println("Document " + getTitle()
						+ " writing is complete");
				setState(State.READY_FOR_REVIEW);
			} else {
				System.out.println("Document " + getTitle() + " is In progress");
			}
		} else {
			System.out.println("Document " + getTitle()
					+ " is not available for writing");
		}
	}

	public void review() {
		if (this.state.equals(State.READY_FOR_REVIEW)) {
			if (content.length() > 20) {
				System.out.println("Document " + getTitle() + " is Accepted");
				setState(State.READY_FOR_PUBLISH);
			} else {
				System.out.println("Document " + getTitle() + " is Rejected");
				setState(State.REJECTED);
			}
		} else {
			System.out.println("Document " + getTitle()
					+ " Not ready for Review");
		}
	}

	public void publish() {
		if (this.state.equals(State.READY_FOR_PUBLISH)) {
			System.out.println("Document " + getTitle() + " Published");
		} else {
			System.out.println("Document " + getTitle()
					+ " Not ready for Publishing");
		}
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getContent() {
		return content;
	}

	public void setContent(String content) {
		this.content = content;
	}

	public State getState() {
		return state;
	}

	public void setState(State state) {
		this.state = state;
	}

}
